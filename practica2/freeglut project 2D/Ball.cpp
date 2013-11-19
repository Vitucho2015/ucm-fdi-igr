#include "Ball.h"


Ball::Ball(PV2D* center, double radius)
{
	int numOfSides = 30;
	double alpha = 2.0*PI/((double)numOfSides);
	double side = 2.0*radius*alpha/(PI-alpha);
	circle = new RegPol(center,numOfSides,side);
	this->center = *center;
	this->radius = radius;
}


Ball::~Ball(void)
{
	delete circle;
}

void Ball::step(){
	center = center + vel;
	circle->move(vel.x,vel.y);
}


void Ball::step(double t){
	center.x = center.x + t*vel.x;
	center.y = center.y + t*vel.y;
	circle->move(t*vel.x,t*vel.y);
}

void Ball::render(){
	circle->render();
}
