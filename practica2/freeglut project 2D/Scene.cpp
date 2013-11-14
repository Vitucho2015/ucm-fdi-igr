/**
	Fichero: Scene.cpp
	Autor: Xavier Gallofré Nieva

	Clase que contiene los datos del Area Visible de la Escena, los datos del árbol que vamos a representar
	y los métodos necesarios para explorar la escena.
*/

#include "Scene.h"


Scene::Scene(void)
{
	xL= 0.0;
	xR= 500.0;
	yB= 0.0;
	yT= 250.0;
	int offset = 50;
	margin[0] = new Triangle(&PV2D(xL-offset,yB),&PV2D(xL,yB),&PV2D(xL,yT+offset));
	margin[1] = new Triangle(&PV2D(xR,yB-offset),&PV2D(xR,yB),&PV2D(xL-offset,yB));
	margin[2] = new Triangle(&PV2D(xR+offset,yT),&PV2D(xR,yT),&PV2D(xR,yB-offset));
	margin[3] = new Triangle(&PV2D(xL,yT+offset),&PV2D(xL,yT),&PV2D(xR+offset,yT));

	ball = new Ball(&PV2D(20,30),5);
	ball->setVel(&PV2D(10,2));
	tree = new Tree();
}


Scene::~Scene(void)
{
	for (int i=0; i<4;i++) delete margin[i];
	delete ball;
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


void Scene::initTree(Square *square){
	tree->initTree(square);
}

void Scene::glow(PV2D *p){
	tree->glow(p);
}

void Scene::newLevel(){
	tree->generateNewLevel();
}

void Scene::retrieveLevel(){
	tree->deleteLastLevel();
}

bool Scene::isEmpty(){
	return tree->isEmpty();
}

void Scene::step(){
	ball->step();
}

void Scene::render(){
	for (int i=0;i<4;i++) margin[i]->render();
	ball->render();
	tree->render();
}
