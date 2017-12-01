//
//		          Programming Assignment #2
//
//			        Victor Zordan
//
//
//
/***************************************************************************/

/* Include needed files */
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
#include "viewer.h"
#include "cgmath.h"

int x_last = 0, y_last = 0;
int biasx = WIDTH / 2;
int biasy = HEIGHT / 2;
int menulevel = 0;
int showt = 0;
int showr = 0;
int showe = 0;
int showframe = 0;
int showperspective = 0;
int sssflag = 0;

float t_step = 2;
float r_angle = 0.1;
float s_ratio = 0.1;

point_t lightsource_p = { (float)-biasx + 50.0f, (float)biasy - 50.0, 0.0f, 1.0f };
point_t camera_p = { 0.0f, 0.0f, 0.0f, 1.0f };

vector_t light_parrallel = { 1.0f, -1.0f, 1.0f, 0.0f };

point_t vertex;
color_t color;
color_t white;
triface_t face;
vertex_index_t vi;
obj_t objdata;
render_t render;

const char* menu[] = {
    "******************************************\n",
    "press T for translation\n",
    "press R for rotation\n",
    "press E for scale\n",
    "press V for perspective\n",
    "press W for switching wireframe/color\n"
};
const char* kcontrol[] = {
    "************************************************************************\n",
    "-- T pressed, enter Translation, use W/S/A/D to control Translation\n",
    "-- R pressed, enter Rotation, use W/S/A/D to control Rotation\n",
    "-- E pressed, enter Scale, use W/S/A/D to control Scale\n",
    "press Q to go back to reset perspective(V) or wireframe/color(W)\n"
};
const char* wcontrol[] = {
    "*********************\n",
    "-- W pressed\n",
    "   -- show wireframe\n",
    "   -- show color\n"
};
const char* vcontrol[] = {
    "***********************\n",
    "-- V pressed\n",
    "   -- show perspective\n",
    "   -- show orthonormal\n"
};

/***************************************************************************/

void init_window() {
    /* Clear the image area, and set up the coordinate system */
    /* Clear the window */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    //glOrtho(0,WIDTH/2,-HEIGHT/2,HEIGHT,-1.0,1.0);
    glOrtho(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2, -1.0, 1.0);
    printf("--- Init Window ---\n");
}

/***************************************************************************/
void display(void) // Create The Display Function
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen

    //write_pixel(x_last, y_last, white);
    view_obj();

    glutSwapBuffers(); // Draw Frame Buffer
}

void mouse(int button, int state, int x, int y)
{
    y *= -1;  //align y with mouse
    y += HEIGHT; //ignore

    y -= HEIGHT / 2;
    x -= WIDTH / 2;

    //y += HEIGHT/2; //ignore
    //x -= WIDTH/2;

    if (state == GLUT_DOWN) { //when the left mouse button is pressed down
        x_last = x;
        y_last = y;
        printf("x %d  y %d\n", x, y);
    }
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
    switch (key) {
    case 27: // When Escape Is Pressed...
        exit(0); // Exit The Program
        break;
    case 't':
        printf("%s%s%s%s", kcontrol[0], kcontrol[1], kcontrol[4], kcontrol[0]);
        menulevel = 1;
        showt = 1;
        showr = 0;
        showe = 0;

        break;
    case 'r':
        printf("%s%s%s%s", kcontrol[0], kcontrol[2], kcontrol[4], kcontrol[0]);
        menulevel = 1;
        showt = 0;
        showr = 1;
        showe = 0;
        break;
    case 'e':
        printf("%s%s%s%s", kcontrol[0], kcontrol[3], kcontrol[4], kcontrol[0]);
        menulevel = 1;
        showt = 0;
        showr = 0;
        showe = 1;
        break;
    case 'v':
        printf("%s%s", vcontrol[0], vcontrol[1]);
        showperspective = 1 - showperspective;
        // if (showperspective == 1 && alreadyperspective == 0) {
        //     //vertices_perspective();
        //     alreadyperspective = 1;
        // }
        // else if (showperspective == 0) {
        //     //vertices_perspective_reverse();
        //     alreadyperspective = 0;
        // }
        if (showperspective == 1) {
            printf("%s%s", vcontrol[2], vcontrol[0]);
        }
        else if (showperspective == 0) {
            printf("%s%s", vcontrol[3], vcontrol[0]);
        }
        break;
    case 'q':
        menulevel = 0;
        showt = 0;
        showr = 0;
        showe = 0;
        for (int i = 0; i < 6; i++) {
            printf("%s", menu[i]);
        }
        printf("%s", menu[0]);
        break;
    case 'w':
        if (menulevel == 0) {
            printf("%s%s", wcontrol[0], wcontrol[1]);
            showframe = 1 - showframe;
            if (showframe == 1) {
                printf("%s%s", wcontrol[2], wcontrol[1]);
            }
            else if (showframe == 0) {
                printf("%s%s", wcontrol[3], wcontrol[1]);
            }
        }
        else if (menulevel == 1) {
            if (showt == 1) {
                vertices_translation(0, t_step, 0);
            }
            else if (showr == 1) {
                vertices_rotation_x(r_angle);
            }
            else if (showe == 1) {
                vertices_scale(1 + s_ratio, 1 + s_ratio, 1 + s_ratio);
            }
        }
        break;
    case 's':
        if (menulevel == 1) {
            if (showt == 1) {
                vertices_translation(0, -t_step, 0);
            }
            else if (showr == 1) {
                vertices_rotation_x(-r_angle);
            }
            else if (showe == 1) {
                vertices_scale(1 - s_ratio, 1 - s_ratio, 1 - s_ratio);
            }
        }

        break;
    case 'a':
        if (menulevel == 1) {
            if (showt == 1) {
                vertices_translation(-t_step, 0, 0);
            }
            else if (showr == 1) {
                vertices_rotation_y(r_angle);
            }
            else if (showe == 1) {
                vertices_scale(1 - s_ratio, 1 - s_ratio, 1 - s_ratio);
            }
        }

        break;
    case 'd':
        if (menulevel == 1) {
            if (showt == 1) {
                vertices_translation(t_step, 0, 0);
            }
            else if (showr == 1) {
                vertices_rotation_y(-r_angle);
            }
            else if (showe == 1) {
                vertices_scale(1 + s_ratio, 1 + s_ratio, 1 + s_ratio);
            }
        }
        break;
    case 'u':
        lightsource_p.z -= 10;
        printf("lightsource_p.z : %f\n", lightsource_p.z);
        break;
    case 'o':
        lightsource_p.z += 10;
        printf("lightsource_p.z : %f\n", lightsource_p.z);
        break;
    case 'i':
        lightsource_p.y += 10;
        printf("lightsource_p.y : %f\n", lightsource_p.y);
        break;
    case 'k':
        lightsource_p.y -= 10;
        printf("lightsource_p.y : %f\n", lightsource_p.y);
        break;
    case 'j':
        lightsource_p.x -= 10;
        printf("lightsource_p.x : %f\n", lightsource_p.x);
        break;
    case 'l':
        lightsource_p.x += 10;
        printf("lightsource_p.x : %f\n", lightsource_p.x);
        break;
    case'z':
        sssflag = 1 - sssflag;
        if (sssflag)
        {
            printf("Subsurface Scattering ON\n");
        }
        else {
            printf("Subsurface Scattering OFF\n");
        }
        break;
    default:
        break;
    }
}

/***************************************************************************/

int main(int argc, char *argv[])
{
    /* This main function sets up the main loop of the program and continues the
    loop until the end of the data is reached.  Then the window can be closed
    using the escape key.						  */

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Computer Graphics");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    init_window();                   //create_window

    obj_loader("./model1.obj");
    printf("obj load done\n");
    color_white(white);
    for (int i = 0; i < 6; i++) {
        printf("%s", menu[i]);
    }
    printf("%s", menu[0]);
    showperspective = 1;
    menulevel = 1;
    showr = 1;
    printf("Default : Perspective Rotation\n");


    glutMainLoop();                 // Initialize The Main Loop
}
