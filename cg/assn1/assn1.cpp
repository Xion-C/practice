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
#define SEG_NUM 50 //The number of segments needed for the curve to look smooth
#define AREA_R 5.5 //The radius of the area around control point that could be clicked
#define ANIME_FRAMES 200 //Control the anitmation speed. The anitmation will be slower when the value increased

int x_last, y_last;
int control_px[P_NUM], control_py[P_NUM];
int init_p = 1;
int click_flag = 0; //mouse click event flag
int chosen_p = 0; //which control point to be changed; if no control point(0 to P_NUM-1) is chosen, the value should be P_NUM
int n_frames = 0; //count the animation frames

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

void init_control_point() //initialize the first 4 control points 
{
	if(click_flag & init_p) {
		control_px[chosen_p] = x_last;
		control_py[chosen_p] = y_last;
		printf("init_p %d - x %d, y %d\n", chosen_p, x_last, y_last);

		if(++chosen_p >= P_NUM) {
			init_p = 0;
		}
		click_flag = 0;
	}	
}

/***************************************************************************/

void set_control_point()
{
	static int x_begin, y_begin;
	init_control_point();
	if(n_frames) { //when one control point is choosen, set the new location by animation
		if(n_frames == ANIME_FRAMES) {
			x_begin = control_px[chosen_p];
			y_begin = control_py[chosen_p];
		}
		control_px[chosen_p] = round(float(x_begin) + float(x_last - x_begin) * float(ANIME_FRAMES - n_frames + 1) / float(ANIME_FRAMES));
		control_py[chosen_p] = round(float(y_begin) + float(y_last - y_begin) * float(ANIME_FRAMES - n_frames + 1) / float(ANIME_FRAMES));

		n_frames--;
		if(n_frames == 0) {
			chosen_p = P_NUM;					
		}
	}
}

/***************************************************************************/

void draw_control_point(float intensity)
/* Draw the area around control point that could be clicked */
{
	int i, x, y;
	int xboundl, xboundh, yboundl, yboundh;
	float intensity_p;

	for(i = 0; i <= (init_p ? chosen_p : P_NUM - 1); i++) {
		intensity_p = (chosen_p == i && n_frames == 0) ? 0.3 * intensity : intensity; //the chosen point area will have lower intensity
		xboundl = control_px[i] - AREA_R > 0 ? control_px[i] - AREA_R : 0;
		xboundh = control_px[i] + AREA_R < WIDTH ? control_px[i] + AREA_R : WIDTH;
		yboundl = control_py[i] - AREA_R > 0 ? control_py[i] - AREA_R : 0;
		yboundh = control_py[i] + AREA_R < HEIGHT ? control_py[i] + AREA_R : HEIGHT;
		for(x = xboundl; x <= xboundh; x++) {
			for(y = yboundl; y <= yboundh; y++) {
				if( (x - control_px[i]) * (x - control_px[i]) + (y - control_py[i]) * (y - control_py[i]) < AREA_R * AREA_R ) {
					write_pixel(x, y, intensity_p);
				}
			}
		} 
	}

}

/***************************************************************************/

void dda_line(int x0, int y0, int x1, int y1) //draw a line using dda algorithm
{
	float m, b;
	int xi, yi;
	if(x1 - x0 == 0) { //when line is horizontal
		for(xi = x0, yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
			write_pixel(xi, yi, 1.0);
		}
	}
	else if(y1 - y0 == 0) { //when line is vertical
		for(xi = (x0 < x1 ? x0 : x1), yi = y0; xi <= (x0 < x1 ? x1 : x0); xi++) {
			write_pixel(xi, yi, 1.0);
		}
	}
	else {
		m = float(y1 - y0) / float(x1 - x0);
		b = float(x1 * y0 - x0 * y1) / float(x1 - x0);
		if (m < 1. && m > -1.) { //when |m|<1
			for(xi = (x0 < x1 ? x0 : x1); xi <= (x0 < x1 ? x1 : x0); xi++) {
				yi = int(round(m * float(xi) + b));
				write_pixel(xi, yi, 1.0);
			}
		}
		else { //when |m|>=1
			for(yi = (y0 < y1 ? y0 : y1); yi <= (y0 < y1 ? y1 : y0); yi++) {
				xi = int(round(1. / m * float(yi) - b / m));
				write_pixel(xi, yi, 1.0);
			}
		}
	}
}

/***************************************************************************/
int C(int n, int k)
{
	int nr = 1, dr = 1;
	for(int i = n - k + 1; i <= n; i++) {
		nr *= i;
	}
	if(k == 0) {
		dr = 1;
	}
	else {
		for(int i = 1; i <= k; i++) {
			dr *= i;
		}
	}
	return nr/dr;
}

float poly_bezier(int *p, int pnum, float u)
/* calculate the polmerization of bezier curve */
{
	float r = 0.0;
	for(int i = 0; i < pnum; i++) {
		r += float(C(pnum - 1, i)) * powf(1 - u, pnum - i - 1) * powf(u, i) * float(p[i]);
	}
	return r;
}

void bezier_curve(int *px, int *py, int pnum, int segs)
/* draw the bezier curve */
{
	float u;
	float x0, xi, y0, yi;
	x0 = float(px[0]);
	y0 = float(py[0]);
	for(int i = 1; i <= segs; i++) {
		u = float(i) / float(segs);
		xi = poly_bezier(px, pnum, u);
		yi = poly_bezier(py, pnum, u);
		dda_line(round(x0), round(y0), round(xi), round(yi));
		x0 = xi;
		y0 = yi;
	}
}

/***************************************************************************/

void display ( void )   // Create The Display Function
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	      // Clear Screen 

	set_control_point();
	draw_control_point(0.5);
	if(!init_p) {
		bezier_curve(control_px, control_py, P_NUM, SEG_NUM);
	}

	glutSwapBuffers();                                      // Draw Frame Buffer 
}

/***************************************************************************/

void mouse(int button, int state, int x, int y)
{
/* This function I finessed a bit, the value of the printed x,y should
   match the screen, also it remembers where the old value was to avoid multiple
   readings from the same mouse click.  This can cause problems when trying to
   start a line or curve where the last one ended */

	int mag;
	static int i = 0;

	y *= -1;  //align y with mouse
	y += HEIGHT; //ignore 

	if(state == GLUT_DOWN) { //when the left mouse button is pressed down
		click_flag = 1;
		printf("mouse click: x %d, y %d\n", x, y);

		x_last = x;
		y_last = y;

		if(chosen_p < P_NUM && init_p == 0) { //if last click chose a point, this time will set it
			n_frames = ANIME_FRAMES;
		}
		else {
			for(int j = 0; j < P_NUM; j++) { //find whether any control point is clicked
				i = i >= P_NUM -1 ? 0 : (i + 1);
				mag = (x_last - control_px[i]) * (x_last - control_px[i]) + (y_last - control_py[i]) * (y_last - control_py[i]);
				if(mag <= AREA_R * AREA_R) { //when a control point is chosen
					chosen_p = i;
					printf("- cotrol point p%d is chosen\n", i);
					break;
				}
			}
		}
	}
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


