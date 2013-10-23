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



void Scene::newLevel(){
	tree->generateNewLevel();
}

void Scene::retrieveLevel(){
	tree->deleteLastLevel();
}

PV2D Scene::convertPV2SVA(int pv_x, int pv_y){
	double sva_x, sva_y;
	//sva_x = xL + pv_x/pv_width * sva_width;
	//sva_y = yT - pv_y/pv_height * sva_height;
	return PV2D(sva_x,sva_y);
}

void Scene::render(){
	tree->render();
}