#include "Scene.h"


Scene::Scene(void)
{
	Square square(new PV2D(250,50),50,0);
	square.setColor(Color(139.0/255,69.0/255,19.0/255));
	tree = new Tree(&square);
}


Scene::~Scene(void)
{
	delete tree;
}

void Scene::move(int dir, double percent){
	switch(dir){
	case 0:
		xL += percent*(xR-xL);
		xR += percent*(xR-xL);
		break;
	case 1:
		yB += percent*(yT-yB);
		yT += percent*(yT-yB);
		break;
	}
}

void Scene::zoom(double factor){

	double oldWidth = (xR - xL);
	double oldHeight= (yT - yB);
	
	double newWidth = oldWidth/factor;
	double newHeight= oldHeight/factor;

	xL -= (newWidth - oldWidth)/2;
	xR += (newWidth - oldWidth)/2;

	yB -= (newHeight - oldHeight)/2;
	yT += (newHeight - oldHeight)/2;
}

void Scene::progressiveZoom(double factor, double nIter){
	GLdouble fIncr = (factor-1)/(GLdouble) nIter;
	GLdouble width = (xR - xL);
	GLdouble height = (yT - yB);
	for (int i=0; i<=nIter;i++){
		GLdouble fAux = 1 + fIncr*i;
		GLdouble newWidth = width/fAux;
		GLdouble newHeight = height/fAux;

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xCenter-newWidth/2.0, xCenter+newWidth/2.0,
					yCenter-newHeight/2.0, yCenter+newHeight/2.0);

		render();
		Sleep(50);
	}
}

void Scene::tilling(int nCols){
	GLdouble SVAratio = (xR-xL)/(yT-yB);
	GLdouble w=(GLdouble)ClientWidth/(GLdouble)nCols;
	GLdouble h=w/SVAratio;

	for (GLint c=0; c<nCols; c++){
		GLdouble currentH = 0;
		while ((currentH+h)<ClientHeight){
			glViewport((GLint)(c*w), (GLint)currentH, (GLint)w,(GLint)h);
			drawScene();
			currentH += h;
		}
	}
}

void Scene::newLevel(){
	tree->generateNewLevel();
}

PV2D Scene::convertPV2SVA(int pv_x, int pv_y){
	double sva_x, sva_y;
	//sva_x = xL + pv_x/pv_width * sva_width;
	return PV2D(sva_x,sva_y);
}

void Scene::render(){
	tree->render();
}