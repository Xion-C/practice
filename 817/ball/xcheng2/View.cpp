/*
   View.cpp

   CPSC 8170 Physically Based Animation Homework1
   Adapted form Dr. Donald H. House

   Implementation for Bouncing-Ball Viewer
 */

#include "View.h"

#ifdef __APPLE__
#  pragma clang diagnostic ignored "-Wdeprecated-declarations"
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif

#include <cstdlib>
#include <iostream>

// Screen width and height, proportions match 1080P
#define WIDTH 960
#define HEIGHT 540

// Distance of near and far clipping planes, and
// camera vertical field-of-view in degrees
#define NEAR  1.0
#define FAR   1000.0
#define FOV   60.0

// Scale of the model, and its initial distance from the camera
#define MODELSIZE   10.0
#define MODELDEPTH  30.0
#define BOXSIZE 20.0
#define BALLSIZE 2.0

// Shading parameters
#define DIFFUSE_FRACTION  0.8
#define SPECULAR_FRACTION 0.2
#define SHININESS         60.0

// Light colors
#define WHITE     0.8, 0.8, 0.8, 1
#define DIM_WHITE 0.4, 0.4, 0.4, 1

// Screen background color
#define GREY_BACKGROUND 0.62, 0.62, 0.62, 1

// Material colors
#define BASE_COLOR  0.6, 0.6, 0.9       // diffuse color
#define HIGHLIGHT_COLOR 1.0, 1.0, 1.0   // specular color

using namespace std;

View::View(Model *model) :
    camera(NULL), themodel(model),
    width(WIDTH), height(HEIGHT),
    near(NEAR), far(FAR), fov(FOV),
    boxsize(model->boxSize()),
    ballsize(model->ballSize()),
    modeldepth(MODELDEPTH),
    diffuse_fraction(DIFFUSE_FRACTION), specular_fraction(SPECULAR_FRACTION), shininess(SHININESS),
    white {
    WHITE
},
dim_white {DIM_WHITE}, grey_background {GREY_BACKGROUND},
base_color {BASE_COLOR}, highlight_color {HIGHLIGHT_COLOR} {

    // Set up camera: parameters are eye point, aim point, up vector,
    // near and far clip plane distances, and camera vertical FOV in degrees
    camera = new Camera(Vector3d(0, 0, modeldepth), Vector3d(0, 0, 0), Vector3d(0, 1, 0),
                        near, far, fov);

    // point to the model
    themodel = model;

    // initialize current window dimensions to match default
    Width = width;
    Height = height;
}

//
// Routine to initialize the state of the viewer to start-up defaults
//
void View::setInitialView(){
    // return camera to its default settings
    camera->Reset();

    // opaque grey background for window
    glClearColor(grey_background[0], grey_background[1], grey_background[2], grey_background[3]);

    // smooth shade across triangles if vertex normals are present
    glShadeModel(GL_SMOOTH);

    // make sure that all surface normal vectors are unit vectors
    glEnable(GL_NORMALIZE);

    // enable dept testing for hidden surfaces
    glEnable(GL_DEPTH_TEST);
    glDepthRange(0.0, 1.0);

    // set the colors of the key, fill, and rim lights
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, dim_white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, dim_white);

    glLightfv(GL_LIGHT2, GL_DIFFUSE, dim_white);
    glLightfv(GL_LIGHT2, GL_SPECULAR, dim_white);

    // turn on lighting
    glEnable(GL_LIGHT0);    // key light
    KeyOn = true;
    glEnable(GL_LIGHT1);    // fill light
    FillOn = true;
    glEnable(GL_LIGHT2);    // rim light
    RimOn = true;

    // turn on shading
    glEnable(GL_LIGHTING);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // consider light position for specular

    // define the diffuse and specular colors of the teapot's material,
    // and set its specular exponent
    float diffuse_color[4], specular_color[4];
    for(int i = 0; i < 3; i++) {
        diffuse_color[i] = diffuse_fraction * base_color[i];
        specular_color[i] = specular_fraction * highlight_color[i];
    }
    diffuse_color[3] = specular_color[3] = 1;

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_color);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_color);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

//
// Position the 3 lights
//
void View::setLights(){
    // key is point light above and behind camera to the left
    const float key_light_position[4] = {-modeldepth / 2, modeldepth / 2, modeldepth / 2, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, key_light_position);

    // fill is point light at eye level to right
    const float fill_light_position[4] = {modeldepth / 2, 0, 0, 1};
    glLightfv(GL_LIGHT1, GL_POSITION, fill_light_position);

    // rim is parallel light coming from behind object, and above and to left
    const float rim_light_direction[4] = {-2 * modeldepth, 2 * modeldepth, -2 * modeldepth, 0};
    glLightfv(GL_LIGHT2, GL_POSITION, rim_light_direction);
}

// Toggle the lights on/off
void View::toggleKeyLight(){
    KeyOn = !KeyOn;
    if(KeyOn)
        glEnable(GL_LIGHT0);
    else
        glDisable(GL_LIGHT0);
}

void View::toggleFillLight(){
    FillOn = !FillOn;
    if(FillOn)
        glEnable(GL_LIGHT1);
    else
        glDisable(GL_LIGHT1);
}

void View::toggleRimLight(){
    RimOn = !RimOn;
    if(RimOn)
        glEnable(GL_LIGHT2);
    else
        glDisable(GL_LIGHT2);
}

// draw the cube and ball
void View::drawModel(){
    // position of end of spout. Note: these magic numbers were determined experimentally
    Vector3d ballOrigin(0, 0, 0);

    // Draw the box
    //glutSolidCube(boxsize);
    glutWireCube(boxsize);

    glTranslatef(-boxsize, 0, 0);
    glutSolidCube(boxsize);
    glTranslatef(boxsize, 0, 0);

    glTranslatef(0, -boxsize, 0);
    glutSolidCube(boxsize);
    glTranslatef(0, boxsize, 0);

    glTranslatef(0, 0, -boxsize);
    glutSolidCube(boxsize);
    glTranslatef(0, 0, boxsize);


    // at its starting position, the bubble is in the teapot spout
    glTranslatef(ballOrigin.x, ballOrigin.y, ballOrigin.z);

    // use the bubble's current position to position it relative to spout
    Vector3d ball = themodel->ballPosition();
    glTranslatef(ball.x, ball.y, ball.z);

    // draw the bubble
    glutSolidSphere(ballsize / 2, 36, 13);
}

//
// Redraw the display, including the model
//
void View::updateDisplay(){
    // clear the window to the background color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // initialize modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // lights are positioned in camera space so they move with camera
    setLights();

    // position and aim the camera in modelview space
    camera->AimCamera();

    // draw the model
    drawModel();

    glutSwapBuffers();
}

//
// handle mouse button events to initiate and end camera motion via mouse movements
//
void View::handleButtons(int button, int state, int x, int y, bool shiftkey){
    camera->HandleMouseEvent(button, state, x, y, shiftkey);
}

//
// handle mouse motion events to move the camera
//
void View::handleMotion(int x, int y){
    camera->HandleMouseMotion(x, y);
}

//
// When window resized, keep viewport proportions the same as the camera's
// viewscreen proportions to avoid distortion of scene
//
void View::reshapeWindow(int w, int h){
    float camaspect = float(width) / float(height); // camera's aspect ratio
    float newaspect = float(w) / float(h);          // current window aspect ratio
    float x0, y0;

    // tentatively set viewport dimensions to current window dimensions
    Width = w;
    Height = h;

    // correct Width or Height so that Width / Height will match camera's aspect ratio
    if(newaspect > camaspect)
        Width = int(h * camaspect);
    else
        Height = int(w / camaspect);

    // offset viewport to keep it centered in the window
    x0 = (w - Width) / 2;
    y0 = (h - Height) / 2;

    // update the viewport
    glViewport(x0, y0, Width, Height);

    // set up camera projection matrix
    camera->PerspectiveDisplay(Width, Height);
}

void View::updateParams()
{
    boxsize = themodel->boxSize();
    ballsize = themodel->ballSize();
}
