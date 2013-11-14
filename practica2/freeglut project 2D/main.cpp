/**
	Fichero: main.cpp
	Autor: Xavier Gallofré Nieva

	Clase principal.
*/


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

//HWND winHandle;

// Scene visible area size
//GLdouble xLeft= 0.0, xRight= 500.0, yBot= 0.0, yTop= 250.0;

Scene scene;

#include "RegPol.h"
RegPol* rp;

bool tillingActive = false;
int nCols = 1;

void intitGL(){

	glClearColor(10.0/255,127.0/255,173.0/255, 1);
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


PV2D convertPV2SVA(int pv_x, int pv_y){
	double sva_x, sva_y;
	double sva_width = (scene.xR - scene.xL);
	double sva_height = (scene.yT - scene.yB);
	sva_x = scene.xL + ((double)pv_x)/WIDTH * sva_width;
	sva_y = scene.yT - ((double)pv_y)/HEIGHT * sva_height;
	return PV2D(sva_x,sva_y);
}

void tilling(int nCols){
	GLdouble SVAratio = (scene.xR-scene.xL)/(scene.yT-scene.yB);
	GLdouble w=(GLdouble)WIDTH/(GLdouble)nCols;
	GLdouble h=w/SVAratio;

	for (GLint c=0; c<nCols; c++){
		GLdouble currentH = 0;
		while ((currentH+h)<=HEIGHT+0.1){
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

  //rp->render();

  glFlush();
  glutSwapBuffers();   
  
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

void progressiveZoom(double factor, double nIter){

	GLdouble fIncr = (factor-1)/(GLdouble) nIter;
	GLdouble width = (scene.xR - scene.xL);
	GLdouble height = (scene.yT - scene.yB);
	GLdouble xCenter = scene.xL + width/2;
	GLdouble yCenter = scene.yB + height/2;

	GLdouble newWidth, newHeight;
	for (int i=0; i<=nIter;i++){
		GLdouble fAux = 1 + fIncr*i;
		newWidth = width/fAux;
		newHeight = height/fAux;	
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xCenter-newWidth/2.0, xCenter+newWidth/2.0,yCenter-newHeight/2.0, yCenter+newHeight/2.0);

		display();		
		Sleep(50);
	}
	scene.xL = xCenter-newWidth/2.0;
	scene.xR = xCenter+newWidth/2.0;
	scene.yB = yCenter-newHeight/2.0; 
	scene.yT = yCenter+newHeight/2.0;
}

void key(unsigned char key, int x, int y){
	
	bool need_redisplay = true;
	
	switch (key) {
		case 27:  /* Escape key */
		//continue_in_main_loop = false; // (**)
		glutLeaveMainLoop (); //Freeglut's sentence for stopping glut's main loop (*)
		break;
		/*
		case 'a' : scene.move(0,+MOVE_FACTOR); break;
		case 'd' : scene.move(0,-MOVE_FACTOR); break;  
		case 's' : scene.move(1,+MOVE_FACTOR); break;
		case 'w' : scene.move(1,-MOVE_FACTOR); break;
		*/

		case 'n' : scene.step(); break;
		case 'a' : scene.move(0,-MOVE_FACTOR); break;
		case 'd' : scene.move(0,+MOVE_FACTOR); break;  
		case 's' : scene.move(1,-MOVE_FACTOR); break;
		case 'w' : scene.move(1,+MOVE_FACTOR); break;

		case '+': scene.zoom(1+ZOOM_FACTOR); break;
		case '-': scene.zoom(1-ZOOM_FACTOR); break;

		case '\r': scene.newLevel(); break;
		case '\b': scene.retrieveLevel(); break;

		case 'r': progressiveZoom(1+ZOOM_FACTOR,10); break;
		case 'f': progressiveZoom(1-ZOOM_FACTOR,10); break;

		case '1': tillingActive = true; nCols = 1; break;
		case '2': tillingActive = true; nCols = 2; break;
		case '3': tillingActive = true; nCols = 3; break;
		case '4': tillingActive = true; nCols = 4; break; 
		case '5': tillingActive = true; nCols = 5; break;
		case '6': tillingActive = true; nCols = 6; break;
		case '7': tillingActive = true; nCols = 7; break;
		case '8': tillingActive = true; nCols = 8; break; 
		case '9': tillingActive = true; nCols = 9; break;
		case '0': 
			tillingActive = false; 
			glViewport(0, 0, WIDTH, HEIGHT); //Restore viewPort
			break;

		default : need_redisplay = false; break;
	}//switch

	if (need_redisplay){
		// Scene Visible Area
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(scene.xL, scene.xR, scene.yB, scene.yT);
		glutPostRedisplay();
	}
}


void mouse(int button, int state, int x, int y){

	
	switch (button) {
	
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){
			if (scene.isEmpty()){
				int side = 50;
				/*
				cout<< "Introduce el valor del lado del cuadrado";
				cin >> side;
				*/
				scene.initTree(&Square(&convertPV2SVA(x,y),side,0));
			} else {
				scene.glow(&convertPV2SVA(x,y));
			}
			//Save (x,y) as v0
		}
		//::MessageBox(winHandle, "Se va a crear el cuadrado de base v0v1", "caption", MB_OKCANCEL);
		
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN){
			scene.initTree(&Square(&convertPV2SVA(x,y),50,0));
		}
	default:
		break;
	}
}



int main(int argc, char *argv[]){
	
	rp = new RegPol(&PV2D(100,50),20,30);

  cout<< "Starting console...\n---------------\n" << endl;
  cout<< "Instrucciones de uso:\n\n";
  cout<< " #Teclado#\n";
  cout<< "  Explorar:\t   w,a,s,d\n";
  cout<< "  Zoom:\t\t   +/-\n";
  cout<< "  Zoom progresivo: r/f\n";
  cout<< "  Crear nivel:\t   Enter\n";
  cout<< "  Borrar nivel:\t   Backspace\n";
  cout<< "  Embaldosado:\t   1-9 numero de columnas; 0 desactivar\n\n";
  cout<< " #Raton#\n";
  cout<< "  Click izquierdo: \n\tSi no hay arbol -> crea un cuadrado; \n\tSi hay arbol -> selecciona un cuadrado\n";
  cout<< "  Click derecho:   \n\tBorra el arbol anterior y crea un cuadrado nuevo\n\n";
  system("Pause");
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
  
	//winHandle = ::FindWindow(NULL, argv[0]);
   
  delete rp;
  return 0;
}
