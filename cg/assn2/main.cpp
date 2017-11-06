//
//		          Programming Assignment #1
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

int x_last = 0, y_last = 0;
int biasx = WIDTH/2, biasy=HEIGHT/2;

point_t vertex;
color_t color;
color_t white;
triface_t face;
vertex_index_t vi;
obj_t objdata;
render_t render;

/***************************************************************************/

void init_window() {
/* Clear the image area, and set up the coordinate system */
	/* Clear the window */
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	//glOrtho(0,WIDTH/2,-HEIGHT/2,HEIGHT,-1.0,1.0);
	glOrtho(-WIDTH/2,WIDTH/2,-HEIGHT/2,HEIGHT/2,-1.0,1.0);
	printf("--- Init Window ---\n");
}

/***************************************************************************/
void display ( void ) // Create The Display Function
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen

	color_white(color);
	write_pixel(-100, -100, color);
	// write_pixel(WIDTH/2-2, HEIGHT/2-2, color);
	// //write_pixel(-WIDTH/2+2, -HEIGHT/2+2, color);
	// color_random(color);
	// write_pixel(x_last, y_last, color);
	view_obj();

	glutSwapBuffers(); // Draw Frame Buffer
}

void mouse(int button, int state, int x, int y)
{
	y *= -1;  //align y with mouse
	y += HEIGHT; //ignore

	y-=HEIGHT/2;
	x-=WIDTH/2;

	//y += HEIGHT/2; //ignore
	//x -= WIDTH/2;

	if(state == GLUT_DOWN) { //when the left mouse button is pressed down
		x_last = x;
		y_last = y;
		printf("x %d  y %d\n",x,y);
	}
}
void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27: // When Escape Is Pressed...
			exit ( 0 ); // Exit The Program
			break;
	        case '1': // stub for new screen
		        printf("New screen\n");
			break;
		default:
			break;
	}
}

/***************************************************************************/

int main (int argc, char *argv[])
{
/* This main function sets up the main loop of the program and continues the
   loop until the end of the data is reached.  Then the window can be closed
   using the escape key.						  */

	glutInit            ( &argc, argv );
  glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize  ( WIDTH,HEIGHT );
	glutCreateWindow    ( "Computer Graphics" );
	glutDisplayFunc     ( display );
	glutIdleFunc	      ( display );
	glutMouseFunc       ( mouse );
	glutKeyboardFunc    ( keyboard );

	init_window();				             //create_window

	obj_loader("./model1.obj");
	printf("obj load done\n");
	color_white(white);

	glutMainLoop        ( );                 // Initialize The Main Loop
}
