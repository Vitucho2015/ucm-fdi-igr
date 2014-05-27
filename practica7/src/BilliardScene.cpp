/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardScene.h"


BilliardScene::BilliardScene(void) : Scene(){
	
	BilliardTable* billiard = new BilliardTable();
	childs.push_back(billiard);
		
	Ball* ball = new Ball(0.05);
	ball->color.setColor(0.9,0.9,0.9);
	ball->mT.translate(1.2,billiard->getHeight()+0.05,3);
	childs.push_back(ball);
	
	Balls* balls = new Balls();
	balls->mT.translate(0.9,billiard->getHeight(),1);
	childs.push_back(balls);
	
	Chalk* chalk = new Chalk(0.1);
	chalk->mT.rotate(-90,0,0);
	chalk->mT.translate(0.05,2.2,0.15);	
	childs.push_back(chalk);

	Cylinder* taco = new Cylinder(0.05,0.025,2.5,10,10);
	taco->color.setColor(100.0/255,50.0/255,11.0/255);
	taco->mT.rotate(170,0,0);
	taco->mT.translate(1.2,billiard->getHeight()+0.75,6);
	childs.push_back(taco);
		
	spotlight = new Spotlight(0.25,0.75);
	spotlight->mT.translate(0.9,billiard->getHeight()+1,1);
	childs.push_back(spotlight);
		
}

void BilliardScene::setup_fog(){

	fog = new Fog(0,50,0.15);
	fog->setColor(RGBColor(0.7,0.7,0.7));
	fog->mode_Gaussian();
	fog->update();

}

void BilliardScene::setup_lights(){

	GLfloat zero[]={0,0,0,0};
	GLfloat a0[]={0.3f,0.3f,0.3f,1.0};	
	GLfloat d2[]={1.0, 1.0, 1.0, 1};	

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, zero);

	lights[0] = new Light(GL_LIGHT0);	
	lights[1] = new Light(GL_LIGHT1);
	lights[2] = new Light(GL_LIGHT2);

	//Ambient Light	
    lights[0]->setAmbient(a0);
	lights[0]->setDiffuse(zero);
	lights[0]->setSpecular(zero);
	lights[0]->setLocal_light(false);
	
	//East Light
	lights[2]->setPos(new PV3D(1,1,0));
	lights[2]->setLocal_light(false);
	lights[2]->setDiffuse(d2);

}