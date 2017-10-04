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

#define WIDTH 800
#define HEIGHT 600
#define P_NUM 4 //The number of control points in Bezier curve 
#define SEG_NUM 10 //The number of segments needed for the curve to look smooth
#define AREA_R 5 //The radius of the area around control point that could be clicked

int x_last, y_last;
int control_px[P_NUM], control_py[P_NUM];
int init_p = 1;
int chosen_p = 0; //which control point to be changed; if no control point(0 to P_NUM-1) is chosen, the value should be P_NUM

/***************************************************************************/

void init_window()
/* Clear the image area, and set up the coordinate system */
{

        					       /* Clear the window */
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_SMOOTH);
	glOrtho(0,WIDTH,0,HEIGHT,-1.0,1.0);
	printf("--- Init Window ---\n");
}

/***************************************************************************/

void write_pixel(int x, int y, double intensity)
/* Turn on the pixel found at x,y */
{
	glColor3f (intensity, intensity, intensity);                 
	glBegin(GL_POINTS);
	glVertex3i( x, y, 0);
	glEnd();
}

//***************************************************************************/

void draw_area_around(float intensity)
/* Draw the area around control point that could be clicked */
{
	int i, x, y;
	int xboundl, xboundh, yboundl, yboundh;

	for(i = 0; i <= (init_p ? chosen_p : P_NUM); i++) {
		xboundl = control_px[i] - AREA_R > 0 ? control_px[i] - AREA_R : 0;
		xboundh = control_px[i] + AREA_R < WIDTH ? control_px[i] + AREA_R : WIDTH;
		yboundl = control_py[i] - AREA_R > 0 ? control_py[i] - AREA_R : 0;
		yboundh = control_py[i] + AREA_R < HEIGHT ? control_py[i] + AREA_R : HEIGHT;
		for(x = xboundl; x <= xboundh; x++) {
			for(y = yboundl; y <= yboundh; y++) {
				if( (x - control_px[i]) * (x - control_px[i]) + (y - control_py[i]) * (y - control_py[i]) < AREA_R * AREA_R )
				{
					write_pixel(x, y, intensity);
				}
			}
		}
	}

}

/***************************************************************************/

void dda_line(int x0, int y0, int x1, int y1)
{
	float m, b;
	int xi, yi;
	if(x1 - x0 == 0) { //when line is horizontal
		for(xi = x0, yi = y0; yi <= y1; yi++) {
			write_pixel(xi, yi, 1.0);
		}
	}
	else if(y1 - y0 == 0) { //when line is vertical
		for(xi = x0, yi = y0; xi <= x1; xi++) {
			write_pixel(xi, yi, 1.0);
		}
	}
	else {
		m = float(y1 - y0) / float(x1 - x0);
		b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
		if (m < 1. && m > -1.) { //when |m|<1
			for(xi = x0; xi <= x1; xi++) {
				yi = int(round(m * float(xi) + b));
				write_pixel(xi, yi, 1.0);
			}
		}
		else { //when |m|>=1
			for(yi = y0; yi <= y1; yi++) {
				xi = int(round(1. / m * float(yi) - b / m));
				write_pixel(xi, yi, 1.0);
			}
		}
	}
}

/***************************************************************************/

void bezier_curve(int *px, int *py)
{

}

/***************************************************************************/

void display ( void )   // Create The Display Function
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen 

	if(init_p) { //initialize the first 4 control points 
		control_px[chosen_p] = x_last;
		control_py[chosen_p] = y_last;
		write_pixel(x_last,y_last,1.0);
		draw_area_around(0.5);
		if(++chosen_p >= P_NUM) {
			init_p = 0;
		}
	}
	else {
		if(chosen_p < P_NUM) { //when one control point is choosen, set the new location
			control_px[chosen_p] = x_last;
			control_py[chosen_p] = y_last;
			chosen_p = P_NUM;
		}
		bezier_curve(control_px, control_py);
		draw_area_around(0.5);
	}
	

	//write_pixel(x_last,y_last,1.0);
	//dda_line(10, 20, x_last, y_last);

	glutSwapBuffers();                                      // Draw Frame Buffer 
}

/***************************************************************************/

void mouse(int button, int state, int x, int y)
{
/* This function I finessed a bit, the value of the printed x,y should
   match the screen, also it remembers where the old value was to avoid multiple
   readings from the same mouse click.  This can cause problems when trying to
   start a line or curve where the last one ended */
	static int oldx = 0;
	static int oldy = 0;
	int mag;

	y *= -1;  //align y with mouse
	y += HEIGHT; //ignore 
	for(static int i = 0; i < P_NUM; i++) {
		mag = (oldx - control_px[i]) * (oldx - control_px[i]) + (oldy - control_py[i]) * (oldy - control_py[i]);
		if(mag <= AREA_R * AREA_R) { //when a control point is chosen
			chosen_p = i;
			printf("cotrol point p%d is chosen\n", i);
			break;
		}
		if(i >= P_NUM) { i = 0; }
	}

	oldx = x;
	oldy = y;
	x_last = x;
	y_last = y;
}
 
/***************************************************************************/

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{

	switch ( key ) {
		case 27:              // When Escape Is Pressed...
			exit ( 0 );   // Exit The Program
			break;        
	        case '1':             // stub for new screen
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
	glutIdleFunc	    ( display );
	glutMouseFunc       ( mouse );
	glutKeyboardFunc    ( keyboard );
        					      
    init_window();				             //create_window
						       		
	glutMainLoop        ( );                 // Initialize The Main Loop
}


