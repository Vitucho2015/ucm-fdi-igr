
#include "WFormGL.h"

using namespace WinCliOpenGL;
    
GLvoid WFormGL::InitGL(){
  glShadeModel(GL_SMOOTH);							// Enable smooth shading
	glClearColor(10.0/255, 127.0/255, 173.0/255, 1.0f);	// Black background
	//glClearColor(0.0/255, 172.0/255, 107.0/255, 1.0f);	// Black background
	glPointSize(4.0);
	//glClearDepth(1.0f);									  // Depth buffer setup
	//glEnable(GL_DEPTH_TEST);							// Enables depth testing
	//glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
}

GLvoid WFormGL::GLScene(){
  glClear(GL_COLOR_BUFFER_BIT/* | GL_DEPTH_BUFFER_BIT*/);	// Clear screen and depth buffer

  // comandos para dibujar la escena
  scene-> render(this->contornosToolStripMenuItem->Checked, this->colaToolStripMenuItem->Checked);

  glFlush();
  nwOpenGL->SwapBuffersGL() ;
}

GLvoid WFormGL::ReSizeGL(GLsizei width, GLsizei height){
	/**
	if (height==0)	height=1;			// Prevent A Divide By Zero By (Making Height Equal One)
											
	nwOpenGL->ResizeGL(width,height); // ahora no hace nada, en su lugar ViewportGL
	glViewport(0,0,width,height);						// Reset The Current Viewport

	//nwOpenGL->ViewportGL(0,0,width,height);
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	gluOrtho2D(scene->xL, scene->xR, scene->yB, scene->yT);

	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	**/
	

	
	//se actualiza puerto de vista y su radio
	if ((ClientSize.Width<=1)||(ClientSize.Height<=1)){
		this->ClientSize = System::Drawing::Size(400, 400);
		RatioViewPort=1.0;
	}
	else RatioViewPort= (float)ClientSize.Width/(float)ClientSize.Height;
          
	// NUEVO AJUSTE
	//glViewport(0, (COpenGL::wnHeight)-ClientSize.Height, ClientSize.Width, ClientSize.Height); 
	nwOpenGL->ResizeGL(width,height);
	glViewport(-width,-height,width*2,height*2);  
	// se actualiza el volumen de vista
	// para que su radio coincida con ratioViewPort
	GLfloat RatioVolVista=scene->xR/scene->yT;

	if (RatioVolVista>=RatioViewPort){
		//Aumentamos yTop-yBot
		scene->yT= scene->xR/RatioViewPort;
		scene->yB=-scene->yT;
	}
	else{
		//Aumentamos xRight-xLeft
		scene->xR=RatioViewPort*scene->yT;
		scene->xL=-scene->xR;
	}


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(scene->xL,scene->xR, scene->yB,scene->yT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	GLScene();
		 
}


