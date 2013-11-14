#include "Ball.h"


Ball::Ball(PV2D* center, double radius)
{
	circle = new RegPol(center,30,radius);
}


Ball::~Ball(void)
{
	delete circle;
}

void Ball::step(){
	//center = center + vel;
	circle->move(vel.x,vel.y);
}

void Ball::render(){
	circle->render();
}

void Ball::setVel(PV2D* vel){
	this->vel = *vel;
}