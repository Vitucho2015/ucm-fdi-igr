/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardScene.h"


BilliardScene::BilliardScene(void) : Scene(){
	
	BilliardTable* billiard = new BilliardTable();
	addObject(billiard);
	
	Ball* ball = new Ball(0.05);
	ball->color.setColor(0.9,0.9,0.9);
	ball->mT.translate(1,0.15,3);
	addObject(ball);

	Balls* balls = new Balls();
	balls->mT.translate(0.35,0.05,0.35);
	addObject(balls);
	
	Chalk* chalk = new Chalk(0.1);
	chalk->mT.rotate(-45,0,0);
	chalk->mT.translate(0,0.05,0.15);
	
	addObject(chalk);

	Cylinder* taco = new Cylinder(0.05,0.025,2.5,10,10);
	taco->color.setColor(100.0/255,50.0/255,11.0/255);
	taco->mT.rotate(170,0,0);
	taco->mT.translate(1,0.75,6);
	addObject(taco);

	mT.translate(0,2,0);
	
}

