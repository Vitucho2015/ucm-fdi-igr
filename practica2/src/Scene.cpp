/**
	Fichero: Scene.cpp
	Autor: Xavier Gallofré Nieva

	Clase que contiene los datos del Area Visible de la Escena, los datos del árbol que vamos a representar
	y los métodos necesarios para explorar la escena.
*/

#include "Scene.h"


Scene::Scene(void)
{
	
	srand(time(NULL));
	initScene(1);
	initBall();
}


Scene::~Scene(void)
{
	for (Obstacle* o: obstacles) {
		delete o;
	}
	delete ball;
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

void Scene::step(){
	//Check Collissions
	double tIn, tHitG = 2;
	PV2D *normal, *normalG;
	bool succL, succG = false;
	for (Obstacle* o: obstacles){
		succL = o->collisionDetection(ball->getCenter(), ball->getVel(), tIn, normal);
		if (succL && tIn > 0 && tIn <= 1){ //TODO: Check range
			if (tIn < tHitG ){
				tHitG = tIn;				
				normalG = normal;
			}
			succG |= succL;
		}
		
	}
	if (!succG)
		ball->step(1);
	else {
		ball->step(tHitG);
		ball->bounce(normalG);
	}
}

void Scene::render(bool debug){
	ball->render(debug);
	for (Obstacle* o: obstacles) o->render(debug);	
}

void Scene::initBall(){
	
	if (ball == nullptr){
		delete ball;
		ball = nullptr;
	}
	ball = new Ball(&PV2D(300,200),20);
	
	
	int grados = (rand() % 360);
	float alpha = ((float) grados)/360 * 2 * PI;
	PV2D vel = PV2D(5*cos(alpha),5*sin(alpha));
	ball->setVel(&vel);
	
}

void Scene::initScene(int i){
	xL= 0.0;	xR= 500.0;
	yB= 0.0;	yT= 250.0;
	if (!obstacles.empty()) obstacles.clear();
	int offset = 50;

	//Room
	Triangle* nextTri;
	Circle* nextCirc;
	nextTri = new Triangle(&PV2D(xL-offset,yB),&PV2D(xL,yB),&PV2D(xL,yT+offset));
	obstacles.push_back(nextTri);
	nextTri = new Triangle(&PV2D(xR,yB-offset),&PV2D(xR,yB),&PV2D(xL-offset,yB));
	obstacles.push_back(nextTri);
	nextTri = new Triangle(&PV2D(xR+offset,yT),&PV2D(xR,yT),&PV2D(xR,yB-offset));
	obstacles.push_back(nextTri);
	nextTri = new Triangle(&PV2D(xL,yT+offset),&PV2D(xL,yT),&PV2D(xR+offset,yT));
	obstacles.push_back(nextTri);

	switch (i){
		case 1:		

			nextTri = new Triangle(&PV2D(100,0),&PV2D(200,0),&PV2D(200,50));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
			
			nextTri = new Triangle(&PV2D(400,50),&PV2D(400,150),&PV2D(300,150));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
			
			nextTri = new Triangle(&PV2D(75,150),&PV2D(100,225),&PV2D(50,200));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
	
			nextCirc = new Circle(&PV2D(300,100), 25);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);
			
			nextCirc = new Circle(&PV2D(150,150), 40);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);
			
			nextCirc = new Circle(&PV2D(450,200), 10);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);

			break;

		case 2:

			nextTri = new Triangle(&PV2D(0,0),&PV2D(200,0),&PV2D(0,100));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
			
			nextTri = new Triangle(&PV2D(300,0),&PV2D(500,0),&PV2D(400,150));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
			
			nextTri = new Triangle(&PV2D(0,150),&PV2D(100,250),&PV2D(0,250));
			nextTri->setColor(RGBColor(125,50,0));
			obstacles.push_back(nextTri);
	
			nextCirc = new Circle(&PV2D(300,50), 50);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);
			
			nextCirc = new Circle(&PV2D(200,175), 25);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);
			
			nextCirc = new Circle(&PV2D(500,250), 60);
			nextCirc->setColor(RGBColor(66,14,156));
			obstacles.push_back(nextCirc);

			break;
	}

	initBall();
}