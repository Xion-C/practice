/*
   Adapted from Dr. Donald H. House

   usage: run parameters
 */

#include "FlockingSystem.h"
#include "Model.h"
#include "ParameterLoader.h"
#include "ParticleCluster.h"
#include "ParticleGenerator.h"
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
Model boxModel;
ParticleCluster particles;
ParticleGenerator particleGen(&boxModel, &particles);
FlockingParticles flocking(&boxModel, &particles);

ParameterLoader params;

//===========================================================================
// View
//===========================================================================

// Create the teapot viewer with pointer to the model
View viewer(&boxModel, &particleGen, &flocking);

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

            boxModel.loadParameters(params);
            boxModel.printParameters();
            boxModel.initSimulation();

            particles.Clear();

            // particleGen.LoadParameters(params);
            // particleGen.PrintParameters();
            // particleGen.Init();
            particleGen.LoadParameters(params);
            particleGen.GenerateCubeParticles(params.particleNum);

            flocking.LoadParameters(params);
            flocking.Init();

            break;

        case ' ':
            pause = !pause;
            if (pause)
                std::cout << "pause" << '\n';
            else
                std::cout << "resume" << '\n';
            break;
        case 'p':
            flocking.ToggleRoute();

        // keyboard transform
        case 'a':
            // particleGen.Translate(Vector3d(-TRANSLATESPEED, 0, 0));
            flocking.MoveLeadBoid(Vector3d(-TRANSLATESPEED, 0, 0));
            break;
        case 'd':
            // particleGen.Translate(Vector3d(TRANSLATESPEED, 0, 0));
            flocking.MoveLeadBoid(Vector3d(TRANSLATESPEED, 0, 0));
            break;
        case 'w':
            // particleGen.Translate(Vector3d(0, TRANSLATESPEED, 0));
            flocking.MoveLeadBoid(Vector3d(0, TRANSLATESPEED, 0));
            break;
        case 's':
            // particleGen.Translate(Vector3d(0, -TRANSLATESPEED, 0));
            flocking.MoveLeadBoid(Vector3d(0, -TRANSLATESPEED, 0));
            break;
        case 'q':
            // particleGen.Translate(Vector3d(0, 0, -TRANSLATESPEED));
            flocking.MoveLeadBoid(Vector3d(0, 0, -TRANSLATESPEED));
            break;
            break;
        case 'e':
            // particleGen.Translate(Vector3d(0, 0, TRANSLATESPEED));
            flocking.MoveLeadBoid(Vector3d(0, 0, TRANSLATESPEED));
            break;
            break;

        case 't':
            pause = false;
            particleGen.Stop();
            particleGen.GenerateRectPaticles(1);
            flocking.Init();
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
void doDisplay() { viewer.updateDisplay(); }

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
        flocking.TimeStep();
    }
    // pause = true;

    if (count ==
        0)  // only update the display after every displayinterval time steps
    {
        glutPostRedisplay();
        // boxModel.print();
    }

    count = (count + 1) % boxModel.displayInterval();
}

//
// Main program to create window, initiate GLUT, setup callbacks,
// and initialize Model and View
//
int main(int argc, char* argv[]) {
    // make sure we have exactly one parameter
    if (argc != 2) {
        cerr << "usage: canoncial paramfilename" << endl;
        return 1;
    }
    paramfilename = argv[1];

    // start up the glut utilities
    glutInit(&argc, argv);

    // create the graphics window, giving width, height, and title text
    // and establish double buffering, RGBA color
    // Depth buffering must be available for drawing the shaded model
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(viewer.getWidth(), viewer.getHeight());
    glutCreateWindow("Canonical 3D Animation Example");

    // register callback to handle events
    glutDisplayFunc(doDisplay);
    glutReshapeFunc(doReshape);
    glutKeyboardFunc(handleKey);
    glutMouseFunc(handleButtons);
    glutMotionFunc(handleMotion);

    // idle function is run whenever there are no other events to process
    glutIdleFunc(doSimulation);

    // set up the camera viewpoint, materials, and lights
    viewer.setInitialView();

    // load parameters and initialize the model
    params.LoadParameters(paramfilename);
    // boxModel.loadParameters(paramfilename);
    boxModel.loadParameters(params);
    boxModel.initSimulation();

    particleGen.LoadParameters(params);
    particleGen.GenerateCubeParticles(params.particleNum);

    flocking.LoadParameters(params);
    flocking.Init();

    viewer.updateParams();

    glutMainLoop();
}
