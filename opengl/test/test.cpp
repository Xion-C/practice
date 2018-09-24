/*
   Adapted from Dr. Donald H. House

   usage: test paramfiled
 */

#include "Model.h"
#include "View.h"
#include "ParameterLoader.h"

#include <cstdlib>
#include <iostream>

#ifdef __APPLE__
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

using namespace std;

//===========================================================================
// Model
//===========================================================================

// Create the model for simulating process
Model ballModel;

ParameterLoader params;

//===========================================================================
// View
//===========================================================================

// Create the teapot viewer with pointer to the model
View bouncingBall(&ballModel);

//===========================================================================
// Controller
//===========================================================================

// global needed to share parameter filename among callbacks
char *paramfilename;

//
// Keyboard callback routine.
// Send model and view commands based on key presses
//
void handleKey(unsigned char key, int x, int y){
    const int ESC = 27;

    switch(key) {
    case 'b':            // begin
        ballModel.loadParameters(params); // reload parameters in case they have changed
        ballModel.initSimulation();
        ballModel.startBall();
        break;

    case 'k':           // toggle key light on and off
        bouncingBall.toggleKeyLight();
        break;

    case 'f':           // toggle fill light on and off
        bouncingBall.toggleFillLight();
        break;

    case 'r':           // toggle rim light on and off
        bouncingBall.toggleRimLight();
        break;

    case 'i':           // I -- reinitialize view
    case 'I':
        bouncingBall.setInitialView();
        break;
    case 'p':
        ballModel.print();
        break;
    case '1':
        ballModel.toggleHaveVel();
        break;
    case '2':
        ballModel.toggleHaveAir();
        break;
    case '3':
        ballModel.toggleHaveWind();
        break;
    case '4':
        ballModel.toggleHaveLight();
        break;
    case 'q':           // Q or Esc -- exit program
    case 'Q':
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

    bouncingBall.handleButtons(button, state, x, y, shiftkey);
    glutPostRedisplay();
}

//
// let the View handle mouse motion events
//
void handleMotion(int x, int y) {
    bouncingBall.handleMotion(x, y);
    glutPostRedisplay();
}

//
// let the View handle display events
//
void doDisplay(){
    bouncingBall.updateDisplay();
}

//
// let the View handle reshape events
//
void doReshape(int width, int height){
    bouncingBall.reshapeWindow(width, height);
}

//
// let the Model handle simulation timestep events
//
void doSimulation(){
    static int count = 0;

    ballModel.timeStep();

    if(count == 0)       // only update the display after every displayinterval time steps
    {
        glutPostRedisplay();
        //ballModel.print();
    }

    count = (count + 1) % ballModel.displayInterval();
}

//
// Main program to create window, initiate GLUT, setup callbacks,
// and initialize Model and View
//
int main(int argc, char* argv[]){

    // make sure we have exactly one parameter
    if(argc != 2) {
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
    glutInitWindowSize(bouncingBall.getWidth(), bouncingBall.getHeight());
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
    bouncingBall.setInitialView();

    // load parameters and initialize the model
    params.LoadParameters(paramfilename);
    //ballModel.loadParameters(paramfilename);
    ballModel.loadParameters(params);
    ballModel.initSimulation();
    bouncingBall.updateParams();


    glutMainLoop();
}
