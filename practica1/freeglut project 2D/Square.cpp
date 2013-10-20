#include "Square.h"


Square::Square(PV2D* v0, PV2D* v1){
	
	Turtle *turtle = new Turtle(v0);
	vertex[0] = turtle->getPosition();
	PV2D v0_v1 = (*v1 - *v0);
	double side = (*v1 - *v0).mod();
	double angle = (*v1 - *v0).angle();
	
	turtle->turnTo(angle);
	turtle->forward(side);
	vertex[1] = turtle->getPosition();

	turtle->turnTo(PI/2);
	turtle->forward(side);
	vertex[2] = turtle->getPosition();

	turtle->turnTo(PI/2);
	turtle->forward(side);
	vertex[3] = turtle->getPosition();

	delete turtle;
}

Square::Square(PV2D* center, double side, double rad){
	
	Turtle *turtle = new Turtle(center);
	
	turtle->turnTo(rad+(5*PI)/4);
	turtle->forward(sqrt((side*side)/2));
	vertex[0] = turtle->getPosition();

	turtle->turnTo((3*PI)/4);
	turtle->forward(side);
	vertex[1] = turtle->getPosition();

	turtle->turnTo(PI/2);
	turtle->forward(side);
	vertex[2] = turtle->getPosition();

	turtle->turnTo(PI/2);
	turtle->forward(side);
	vertex[3] = turtle->getPosition();

	delete turtle;
}

Square::~Square(void)
{
}

PV2D Square::getVertex(int i){
	//if (i<0 || i>=4) return 0;
	return vertex[i];
}

double Square::getSide(){
	PV2D side = vertex[1] - vertex[0];
	return side.mod();
}

void Square::render(){
	glColor3d(color.r,color.g,color.b);
	glBegin ( GL_QUADS ) ;
	for (int i=0;i<4;i++) glVertex2d(vertex[i].x,vertex[i].y);
	glEnd () ;
}

void Square::setColor(Color color){
	this->color = color;
}