#include "PBAEngine.h"
#include "Common.h"
#include "ParameterLoader.h"

#include "Breakout_Scene.h"

#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

PBAEngine* PBAEngine::instance = NULL;

PBAEngine::PBAEngine() : 
    viewer(),
    keyboard(),
    scene(new BreakoutScene())
{

}

PBAEngine::~PBAEngine()
{
    delete scene;
}

PBAEngine* PBAEngine::GetInstance()
{
    if(!instance) 
        instance = new PBAEngine();
    return instance;
}

const PBAKeyboardManager& PBAEngine::GetKeyboard() const 
{
    return keyboard;
}

const PBAMouseManager& PBAEngine::GetMouse() const 
{
    return mouse;
}

const View& PBAEngine::GetView() const 
{
    return viewer;
}


int PBAEngine::InitGlut(int argc, char* argv[])
{
    // start up the glut utilities
    glutInit(&argc, argv);

    // create the graphics window, giving width, height, and title text
    // and establish double buffering, RGBA color
    // Depth buffering must be available for drawing the shaded model
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(viewer.getWidth(), viewer.getHeight());
    glutCreateWindow("Physically Based Animation");

    // register callback to handle events
    glutDisplayFunc(DisplayWrapper);
    glutReshapeFunc(ReshapeWrapper);
    glutKeyboardFunc(HandleKeyWrapper);
    glutMouseFunc(HandleMouseButtonsWrapper);
    glutMotionFunc(HandleMouseMotionWrapper);
    glutPassiveMotionFunc(HandleMousePassiveMotionWrapper);

    // idle function is run whenever there are no other events to process
    glutIdleFunc(UpdateWrapper);

    return 0;
}

void PBAEngine::Reshape(int width, int height)
{
    viewer.reshapeWindow(width, height);
}

void PBAEngine::HandleKey(unsigned char key, int x, int y)
{
    const int ESC = 27;

    // IFDEBUG(
    //     std::cout << "----- keyboard -----" << std::endl;
    // )


    keyboard.SetKey(key, x, y);
    switch(key)
    {
        case 'b':
            LoadParameters();
            scene->Clear();
            scene->Init();
            scene->pause = false;
            
            break;
        case 'a': 
            // IFDEBUG(
            //     std::cout << "press a" << std::endl;
            // )
            break;
        case 'd': 
            // IFDEBUG(
            //     std::cout << "press d" << std::endl;
            // )
            break;
        case ' ':
            scene->pause = !(scene->pause);
            break;
        case ESC:
            exit(0);
        default: 
            break;
    }
    // always refresh the display after a key press
    //glutPostRedisplay();
}

void PBAEngine::HandleMouseButtons(int button, int state, int x, int y)
{
    bool shiftkey = (glutGetModifiers() == GLUT_ACTIVE_SHIFT);

    viewer.handleButtons(button, state, x, y, shiftkey);

    if(state == GLUT_DOWN) {
        mouse.Click();
    }

    glutPostRedisplay();
}

void PBAEngine::HandleMouseMotion(int x, int y)
{
    viewer.handleMotion(x, y);
    glutPostRedisplay();
}

void PBAEngine::HandleMousePassiveMotion(int x, int y)
{
    mouse.SetMotion(x, y);
    glutPostRedisplay();
}

void PBAEngine::ReshapeWrapper(int width, int height)
{
    instance->Reshape(width, height);
}

void PBAEngine::HandleKeyWrapper(unsigned char key, int x, int y)
{
    instance->HandleKey(key, x, y);
}

void PBAEngine::HandleMouseButtonsWrapper(int button, int state, int x, int y)
{
    instance->HandleMouseButtons(button, state, x, y);
}

void PBAEngine::HandleMouseMotionWrapper(int x, int y)
{
    instance->HandleMouseMotion(x, y);
}

void PBAEngine::HandleMousePassiveMotionWrapper(int x, int y)
{
    instance->HandleMousePassiveMotion(x, y);
}


void PBAEngine::DisplayWrapper()
{
    instance->Display();
}

void PBAEngine::UpdateWrapper()
{
    instance->Update();
}

void PBAEngine::LoadParameters(const char* path)
{
    static std::string filepath;
    if(path) {
        filepath = std::string(path);
    }
    ParameterLoader::GetInstance().LoadParameters(filepath.c_str());

}


int PBAEngine::Init(int argc, char* argv[])
{
    InitGlut(argc, argv);
    viewer.setInitialView();
    std::string paramfile;

    if(argc < 2) {
        // cerr << "You need parameter file" << endl;
        // exit(1);
        paramfile = std::string("parameters");
    }
    else {
        paramfile = std::string(argv[1]);
    }

    //ParameterLoader::GetInstance().LoadParameters(argv[1]);
    LoadParameters(paramfile.c_str());

    return 0;
}

int PBAEngine::Start()
{
    scene->Init();

    glutMainLoop();
}

void PBAEngine::Update()
{
    static int count = 0;

    if(!(scene->pause))
        scene->Update();

    // only update the display after every displayinterval time steps
    if (count == 0)
    {
        glutPostRedisplay();
    }

    //count = (count + 1) % displayInterval;
    // IFDEBUG(
    //     std::cout << "***** Engine Update *****" << std::endl;
    // )

    keyboard.Reset();
    mouse.Reset();
}

void PBAEngine::Display()
{
    viewer.updateDisplay();

    scene->Display();

    glutSwapBuffers();
}