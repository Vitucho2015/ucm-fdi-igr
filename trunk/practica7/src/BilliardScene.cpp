/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardScene.h"


BilliardScene::BilliardScene(void) : Scene(){
	
	BilliardTable* billiard = new BilliardTable();
	//addObject(billiard);
	childs.push_back(billiard);

	Ball* ball = new Ball(0.05);
	ball->color.setColor(0.9,0.9,0.9);
	ball->mT.translate(1,0.15,3);
	//addObject(ball);
	childs.push_back(ball);

	Balls* balls = new Balls();
	balls->mT.translate(0.35,0.05,0.35);
	//addObject(balls);
	childs.push_back(balls);

	Chalk* chalk = new Chalk(0.1);
	chalk->mT.rotate(-45,0,0);
	//chalk->mT.translate(0,0.05,0.15);
	chalk->mT.translate(1,0,1);
	
	//addObject(chalk);
	childs.push_back(chalk);

	Cylinder* taco = new Cylinder(0.05,0.025,2.5,10,10);
	taco->color.setColor(100.0/255,50.0/255,11.0/255);
	taco->mT.rotate(170,0,0);
	taco->mT.translate(1,0.75,6);
	//addObject(taco);
	childs.push_back(taco);

	//mT.translate(0,2,0);

	for (Object3D* o : childs) o->setRecoatMode(1);



	lights[0] = new Light(GL_LIGHT0);
	
	GLfloat d0[]={0,0,0,1};
    GLfloat a0[]={0.3f,0.3f,0.3f,1.0};
	GLfloat p0[]={25.0, 25.0, 0.0, 1.0};	 

	lights[0]->setAmbient(a0);
	lights[0]->setDiffuse(d0);
	lights[0]->setSpecular(d0);
	lights[0]->setLocal_light(false);
	lights[0]->off();
	
	lights[1] = new Light(GL_LIGHT1);
	
	GLfloat d1[]={0.0, 1.0, 0.0, 1};
	GLfloat pos[] = {0,3,0,1};
	glLightfv(GL_LIGHT1, GL_POSITION, pos);

	lights[1]->setDiffuse(d1);
	lights[1]->resetSpecular();

	
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 5.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);
	GLfloat dir[]={0,-1,0};
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	
	lights[1]->on();

	lights[2] = new Light(GL_LIGHT2);
	GLfloat d2[]={1.0, 1.0, 1.0, 1};	
	GLfloat p2[]={25.0, 25.0, 0.0, 1};	
	lights[2]->setPos(new PV3D(1,1,0));
	lights[2]->setLocal_light(false);
	lights[2]->setDiffuse(d2);
	
	lights[2]->off();
}

