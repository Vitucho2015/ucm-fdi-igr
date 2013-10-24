#include "Scene.h"


Scene::Scene(void)
{
	tree = new Tree();
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


void Scene::initTree(Square *square){
	tree->initTree(square);
}

void Scene::newLevel(){
	tree->generateNewLevel();
}

void Scene::retrieveLevel(){
	tree->deleteLastLevel();
}



void Scene::render(){
	tree->render();
}