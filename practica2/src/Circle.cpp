#include "Circle.h"


Circle::Circle(PV2D* center, double radius) // : RegPol(center, 20,s)
{
	int numOfSides = 30;
	double alpha = 2.0*PI/((double)numOfSides);
	double side = 2.0*radius*alpha/2.0;
	circle = new RegPol(center,numOfSides,side);
	this->center = *center;
	this->radius = radius;
}


Circle::~Circle(void)
{
	delete circle;
}

void Circle::render(bool debug){
	circle->render();

	if (debug) {
		glColor3f(1,0,0);
		glBegin(GL_LINES);
			glVertex2d(center.x,center.y);
			glVertex2d(center.x+radius*normal.x,center.y+radius*normal.y);
		glEnd();
	}
	
}

bool Circle::collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){
	double A,B,C;
	PV2D CP = *p - center;
	A = v->dot(v);
	B = 2*CP.dot(v);
	C = CP.dot(&CP) - radius*radius;
	double disc = B*B-4*A*C;
	if (disc < -EPSILON ) return false;
	else if (disc > EPSILON) {
		tIn = (-B-sqrt(disc))/(2*A);
	} else {
		tIn = -B/(2*A);
	}
	PV2D bouncePoint;
	bouncePoint.x = v->x;
	bouncePoint.y = v->y;
	bouncePoint.scale(tIn);
	bouncePoint = bouncePoint + *p;
	
	normal.x = bouncePoint.x - center.x;
	normal.y = bouncePoint.y - center.y;
	normal.nor();
	normalIn = &normal;
	return true;
}