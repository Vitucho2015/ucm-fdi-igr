/**
	Autor: Xavier Gallofré Nieva
*/


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include "elements\RegularPolygon.h"
#include "elements\RollerCoaster.h"
#include "elements\Wheel.h"
#include "elements\Car.h"
#include "elements\Camera.h"

#include "BilliardScene.h"

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters 
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

GLdouble rot_x=0, rot_y=0, rot_z=0;

BilliardScene* scene;
Camera* camera;

void initGL() {	 		 

	scene = new BilliardScene();
	scene->mT.scale(3);

	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	// buildSceneObjects();
	camera = new Camera(new PV3D(10,10,10), new PV3D(0,0,0), new PV3D(0,1,0.00002));

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	 // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={25.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);
 }

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	
	glRotatef(rot_x,1.0,0.0,0.0);
	glRotatef(rot_y,0.0,1.0,0.0);
	glRotatef(rot_z,0.0,0.0,1.0);
		
		scene->render();

	glFlush();
	glutSwapBuffers();
	
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;

	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		
			
		//Eje Z
		case 'a': rot_z += 1; if (rot_z>360) rot_z -= 360; break;
		case 'z': rot_z -= 1; if (rot_z<0) rot_z += 360; break;

		//Walk axis
		case 'e': camera->translate(new PV3D(-0.5,0,0)); break;
		case 'r': camera->translate(new PV3D(0.5,0,0)); break;

		case 'd': camera->translate(new PV3D(0,-0.5,0)); break;
		case 'f': camera->translate(new PV3D(0,0.5,0)); break;

		case 'c': camera->translate(new PV3D(0,0,-0.5)); break;
		case 'v': camera->translate(new PV3D(0,0,0.5)); break;

		//Rotate Camera
		case 'u': camera->roll(0.1); break;
		case 'i': camera->roll(-0.1); break;

		case 'j': camera->yaw(0.1); break;
		case 'k': camera->yaw(-0.1); break;

		case 'n': camera->pitch(0.1); break;
		case 'm': camera->pitch(-0.1); break;
		
		//Projection Type
		case 'o': camera->projection_ortho(); break;
		case 'p': camera->projection_perspective(); break;
		case 'l': camera->projection_oblique(new PV3D(0.05,0.05,1)); break;
		
		//Rotate Camera Axis
		case '1': camera->rotateX(0.1); break;
		case '2': camera->rotateY(0.1); break;
		case '3': camera->rotateZ(0.1); break;
		
		//Camera views
		case '4': camera->setPosition(new PV3D(0,0,5)); break;
		case '5': camera->setPosition(new PV3D(5,0,0)); break;
		case '6': camera->setPosition(new PV3D(0,5,0)); break;
		case '7': camera->setPosition(new PV3D(5,5,5)); break;

		//Others
		//case 'r': rot_x = 0; rot_y = 0; rot_z = 0; break;

		case '8': scene->mT.translate(0.5,0,0);; break;
		case '9': scene->mT.rotate(0,PI/16,0); break;
		case '0': scene->mT.scale(1.1); break;

		default:
			need_redisplay = false;
			break;
	}
	if (need_redisplay)
		glutPostRedisplay();
}

void special(int key, int x, int y){
	bool need_redisplay = true;
	
	switch(key) {

	//Eje X
	case GLUT_KEY_UP:		rot_x -= 1; if (rot_x<0) rot_x += 360;		break;
	case GLUT_KEY_DOWN:		rot_x += 1; if (rot_x>360) rot_x -= 360;	break;

	//Eje Y
	case GLUT_KEY_LEFT:		rot_y -= 1; if (rot_y<0) rot_y += 360;		break;
	case GLUT_KEY_RIGHT:	rot_y += 1; if (rot_y>360) rot_y -= 360;	break;

	default:
		need_redisplay = false;
		break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(special);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	//system("PAUSE"); 
   
	return 0;
}
