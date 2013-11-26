#include "RegPol.h"


RegPol::RegPol(PV2D* center, int num, double side)
{
	this->numOfSides = num;
	this->longOfSide = side;

	vertex = new PV2D[num];
	normal = new PV2D[num];
	Turtle *turtle = new Turtle(center);
	
	double alpha = 2.0*PI/num;
	double beta = (PI-alpha)/2.0;
	
	radius = side/(2.0*sin(alpha/2));

	turtle->forward(radius);
	vertex[0] = turtle->getPosition();
	
	turtle->turnTo(PI-beta);
	for (int i=1;i<num;i++){
		turtle->forward(side);
		vertex[i] = turtle->getPosition();
		turtle->turnTo(PI- 2*beta);
	}
	delete turtle;

	for (int i=0;i<num;i++) normal[i] = (vertex[i]-vertex[(i+1)%num]).normal();
}


RegPol::~RegPol(void)
{
	delete[] vertex;
	delete[] normal;
}


void RegPol::move(double x, double y){
	for (int i=0;i<numOfSides;i++){
		vertex[i].x += x;
		vertex[i].y += y;
	}
}

void RegPol::render(){
	glColor3d(color.r,color.g,color.b);
	glBegin ( GL_POLYGON ) ;
		for (int i=0;i<numOfSides;i++) glVertex2d(vertex[i].x,vertex[i].y);
		glVertex2d(vertex[0].x,vertex[0].y);
	glEnd () ;
}