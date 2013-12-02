#include "Circle.h"


Circle::Circle(PV2D* center, double radius) // : RegPol(center, 20,s)
{
	this->center = center;
	this->radius = radius;
	normalAct = new PV2D();
	int numOfSides = 30;

	double alpha = 2.0*PI/((double)numOfSides);
	double beta = (PI-alpha)/2.0;
	double side = 2.0*radius*alpha/2.0;

	Turtle *turtle = new Turtle(center);

	turtle->forward(radius);
	addVertex(new PV2D(turtle->getPosition()));
	
	turtle->turnTo(PI-beta);
	for (int i=1;i<numOfSides;i++){
		turtle->forward(side);
		addVertex(new PV2D(turtle->getPosition()));
		turtle->turnTo(PI- 2*beta);
	}
	delete turtle;

	closePolygon();
}


Circle::~Circle(void)
{
	delete center; center = nullptr;
	delete normalAct; normalAct = nullptr;
}

void Circle::render(bool debug){
	ConvexPolygon::render(debug);
	if (debug) {
		glColor3f(1,0,0);
		glBegin(GL_LINES);
			glVertex2d(center->x,center->y);
			glVertex2d(center->x+radius*normalAct->x,center->y+radius*normalAct->y);
		glEnd();
	}
	
}

bool Circle::collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){
	double A,B,C;
	PV2D CP = *p - *center;
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
	
	normalAct->x = bouncePoint.x - center->x;
	normalAct->y = bouncePoint.y - center->y;
	normalAct->nor();
	normalIn = normalAct;
	return true;
}

ConvexPolygon* Circle::createBoundingBox(double dist){
	ConvexPolygon* ret;
	ret = new Circle(new PV2D(*center), radius+dist);
	return ret;
}