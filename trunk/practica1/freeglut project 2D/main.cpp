#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>

#include "Scene.h"


using namespace std;


#define MOVE_FACTOR 0.01
#define ZOOM_FACTOR 0.05

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 250;
HWND winHandle;
// Scene visible area size
//GLdouble xLeft= 0.0, xRight= 500.0, yBot= 0.0, yTop= 250.0;

Scene scene;

bool tillingActive = false;
int nCols = 4;

void intitGL(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0); 

	glPointSize(4.0);
	glLineWidth(2.0);

	// Viewport
    glViewport(0, 0, WIDTH, HEIGHT);
    
	// Model transformation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(scene.xL, scene.xR, scene.yB, scene.yT); 
 }


void progressiveZoom(double factor, double nIter){
	int xCenter = WIDTH/2;
	int yCenter = HEIGHT/2;
	GLdouble fIncr = (factor-1)/(GLdouble) nIter;
	GLdouble width = (scene.xR - scene.xL);
	GLdouble height = (scene.yT - scene.yB);
	for (int i=0; i<=nIter;i++){
		GLdouble fAux = 1 + fIncr*i;
		GLdouble newWidth = width/fAux;
		GLdouble newHeight = height/fAux;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xCenter-newWidth/2.0, xCenter+newWidth/2.0,yCenter-newHeight/2.0, yCenter+newHeight/2.0);

		scene.render();
		Sleep(50);
	}
}

void tilling(int nCols){
	GLdouble SVAratio = (scene.xR-scene.xL)/(scene.yT-scene.yB);
	GLdouble w=(GLdouble)WIDTH/(GLdouble)nCols;
	GLdouble h=w/SVAratio;

	for (GLint c=0; c<nCols; c++){
		GLdouble currentH = 0;
		while ((currentH+h)<HEIGHT){
			glViewport((GLint)(c*w), (GLint)currentH, (GLint)w,(GLint)h);
			scene.render();
			currentH += h;
		}
	}
}

void display(void){
  glClear( GL_COLOR_BUFFER_BIT );

  glColor3f(139.0/255,69.0/255,19.0/255);

  if (tillingActive) tilling(nCols);
  else scene.render();

  glFlush();
  glutSwapBuffers();

  // Scene Visible Area
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(scene.xL, scene.xR, scene.yB, scene.yT); 
}


void resize(int newWidth, int newHeight){
  //Resize Viewport
  WIDTH= newWidth;
  HEIGHT= newHeight;
  GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
  glViewport ( 0, 0, WIDTH, HEIGHT ) ;
  
  //Resize Scene Visible Area 
  //Se actualiza el área visible de la escena
  //para que su ratio coincida con ratioViewPort
  GLdouble SVAWidth= scene.xR-scene.xL;
  GLdouble SVAHeight= scene.yT-scene.yB;
  GLdouble SVARatio= SVAWidth/SVAHeight;
  if (SVARatio >= RatioViewPort) {
	 // Increase SVAHeight
     GLdouble newHeight= SVAWidth/RatioViewPort;
	 GLdouble yMiddle= ( scene.yB+scene.yT )/2.0;
     scene.yT= yMiddle + newHeight/2.0;
     scene.yB= yMiddle - newHeight/2.0;
     }
  else {
     //Increase SVAWidth
     GLdouble newWidth= SVAHeight*RatioViewPort;
     GLdouble xMiddle= ( scene.xL+scene.xR )/2.0;
	 scene.xR= xMiddle + newWidth/2.0;
     scene.xL=  xMiddle - newWidth/2.0;
  }

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(scene.xL, scene.xR, scene.yB, scene.yT);
}


void key(unsigned char key, int x, int y){
 
  bool need_redisplay = true;

  switch (key) {
  case 27:  /* Escape key */
    //continue_in_main_loop = false; // (**)
	glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
    break;


  case '+':
	  scene.zoom(1+ZOOM_FACTOR);
	  //progressiveZoom(1+ZOOM_FACTOR, 10);
	  break;

  case '-':
	  scene.zoom(1-ZOOM_FACTOR);
	  break;

  case 'a' :
	  scene.move(0,+MOVE_FACTOR);
	  break;

  case 'd' :
	  scene.move(0,-MOVE_FACTOR);
	  break;
  
  case 's' :
	  scene.move(1,+MOVE_FACTOR);
	  break;

  case 'w' :
	  scene.move(1,-MOVE_FACTOR);
	  break;

  case 'n':
	  scene.newLevel();
	  break;

  case '\r':
	  scene.newLevel();
	  break;

  case '\b':
	  scene.retrieveLevel();
	  break;

  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y){

	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			//Save (x,y) as v0
		} else if (state == GLUT_UP){
			//Save (x,y) as v1 and create the first Square
		}
		//::MessageBox(winHandle, "Se va a crear el cuadrado de base v0v1", "caption", MB_OKCANCEL);
		break;
	default:
		break;
	}
}

int main(int argc, char *argv[]){
	
	scene.xL= 0.0;
	scene.xR= 500.0;
	scene.yB= 0.0;
	scene.yT= 250.0;
  cout<< "Starting console..." << endl;

  int my_window; //my window's identifier

  //Initialization
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition (140, 140);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );
  glutInit(&argc, argv);

  //Window construction
  my_window = glutCreateWindow( "Freeglut 2D-project" );
    
  //Callback registration
  glutReshapeFunc(resize);
  glutKeyboardFunc(key);
  glutDisplayFunc(display);
  glutMouseFunc(mouse);

  //OpenGL basic setting
  intitGL();


  // Freeglut's main loop can be stopped executing (**)
  //while ( continue_in_main_loop )
  //  glutMainLoopEvent();

  // Classic glut's main loop can be stopped after X-closing the window,
  // using the following freeglut's setting (*)
  glutSetOption ( GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION ) ;
    
  // Classic glut's main loop can be stopped in freeglut using (*)
  glutMainLoop(); 
  
	winHandle = ::FindWindow(NULL, argv[0]);
   
  return 0;
}
