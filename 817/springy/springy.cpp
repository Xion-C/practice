/*
   Adapted from Dr. Donald H. House

   usage: run parameters
 */

#include "ParameterLoader.h"
#include "SpringyMeshFlag.h"
#include "View.h"

#include "StateVector.h"

#include <cstdlib>
#include <iostream>

#ifdef __APPLE__
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define TRANSLATESPEED 10.0

using namespace std;

//===========================================================================
// Model
//===========================================================================

// Create the model for simulating process

SpringyMeshFlag springyFlag;

ParameterLoader& params = ParameterLoader::GetInstance();

//===========================================================================
// View
//===========================================================================

// Create the viewer with pointer to the model
View viewer(&springyFlag);

//===========================================================================
// Controller
//===========================================================================

// global needed to share parameter filename among callbacks
char* paramfilename;

// system control
bool pause;

//
// Keyboard callback routine.
// Send model and view commands based on key presses
//
void handleKey(unsigned char key, int x, int y) {
    const int ESC = 27;

    switch (key) {
        case 'b':  // begin
            // reload parameters in case they have changed
            params.LoadParameters(paramfilename);

            break;

        case ' ':
            pause = !pause;
            if (pause)
                std::cout << "pause" << '\n';
            else
                std::cout << "resume" << '\n';
            break;
        case 'p':
            break;
        case 't':
            viewer.setWire();
            break;

        // keyboard transform
        case 'a':
            break;
        case 'd':
            break;
        case 'w':
            break;
        case 's':
            break;
        case 'q':
            break;
        case 'e':
            break;

        case 'k':  // toggle key light on and off
            viewer.toggleKeyLight();
            break;

        case 'f':  // toggle fill light on and off
            viewer.toggleFillLight();
            break;

        case 'r':  // toggle rim light on and off
            viewer.toggleRimLight();
            break;

        case 'i':  // I -- reinitialize view
        case 'I':
            viewer.setInitialView();
            break;
        case ESC:
            exit(0);
    }

    // always refresh the display after a key press
    glutPostRedisplay();
}

//
// let the View handle mouse button events
// but pass along the state of the shift key also
//
void handleButtons(int button, int state, int x, int y) {
    bool shiftkey = (glutGetModifiers() == GLUT_ACTIVE_SHIFT);

    viewer.handleButtons(button, state, x, y, shiftkey);
    glutPostRedisplay();
}

//
// let the View handle mouse motion events
//
void handleMotion(int x, int y) {
    viewer.handleMotion(x, y);
    glutPostRedisplay();
}

//
// let the View handle display events
//
void doDisplay() 
{ 
    viewer.updateDisplay();
}

//
// let the View handle reshape events
//
void doReshape(int width, int height) { viewer.reshapeWindow(width, height); }

//
// let the Model handle simulation timestep events
//
void doSimulation() {
    static int count = 0;

    if (!pause) {
        // boxModel.timeStep();
        // particleGen.TimeStep();
        springyFlag.TimeStep();
    }
    // pause = true;

    if (count ==
        0)  // only update the display after every displayinterval time steps
    {
        glutPostRedisplay();
        // boxModel.print();
    }

    count = (count + 1) % params.displayInterval;
}


int init(int argc, char* argv[])
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
    glutDisplayFunc(doDisplay);
    glutReshapeFunc(doReshape);
    glutKeyboardFunc(handleKey);
    glutMouseFunc(handleButtons);
    glutMotionFunc(handleMotion);

    // idle function is run whenever there are no other events to process
    glutIdleFunc(doSimulation);

}

//
// Main program to create window, initiate GLUT, setup callbacks,
// and initialize Model and View
//
int main(int argc, char* argv[]) {
    // make sure we have exactly one parameter
    if (argc != 2) {
        cerr << "usage: ./springy paramfilename" << endl;
        return 1;
    }
    paramfilename = argv[1];

    //glut init
    init(argc, argv);

    // set up the camera viewpoint, materials, and lights
    viewer.setInitialView();

    // load parameters and initialize the model
    params.LoadParameters(paramfilename);

    springyFlag.Init();
    //springyFlag.PrintInfo();


    glutMainLoop();
}
