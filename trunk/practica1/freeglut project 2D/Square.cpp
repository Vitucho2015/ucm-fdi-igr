/**
	Fichero: Square.cpp
	Autor: Xavier Gallofré Nieva

	Clase que define el cuadrado con sus 4 vertices y un color.
*/

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

bool Square::isInside(double pX, double pY){
	bool ret = false;

	/*
	double xL_max, xR_max,yB_max, yT_max;
	xL_max = xR_max = vertex[0].x;
	yB_max = yT_max = vertex[0].y;
	PV2D aux;
	for (int i=1;i<=3;i++){
		aux = vertex[i];
		if (aux.x > xR_max) xR_max = aux.x;
		if (aux.x < xL_max) xL_max = aux.x;
		if (aux.y > yT_max) yT_max = aux.y;
		if (aux.y < yB_max) yB_max = aux.y;
	}
	if (xL_max < pX && pX < xR_max && yB_max < pY && pY < yT_max) ret = true;
	*/

	PV2D p_mouse(pX,pY);
	PV2D p_center = vertex[2] - vertex[0];
	//p_center *= 0.5;
	p_center.x *= 0.5;
	p_center.y *= 0.5;
	double radio = p_center.mod();
	p_center = vertex[0] + p_center;
	p_mouse = p_mouse - p_center;
	if ( p_mouse.mod() < radio ) ret = true;

	return ret;
}

Color Square::getColor(){
	return color;
}

void Square::setColor(Color color){
	this->color = color;
}
