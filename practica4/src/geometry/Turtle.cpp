/**
	Fichero: Turtle.h
	Autor: Xavier Gallofré Nieva

	Clase que define el lapiz.
*/

#include "Turtle.h"


Turtle::Turtle(void) {
	pos = new PV2D();
	dir = 0;
}

Turtle::Turtle(PV2D* pos) {
	this->pos = new PV2D(pos->x, pos->y);//clone
	dir = 0;
}

Turtle::~Turtle(void)
{
	pos->x = 0;
	pos->y = 0;
	delete pos;
	pos = nullptr;
}

PV2D Turtle::getPosition(){
	return PV2D(*pos);//CHECK It must return a clone
}

GLdouble Turtle::getDir(){
	return dir;
}

void Turtle::moveTo(PV2D* p, bool draw){
	PV2D old = PV2D(*pos);
	pos->x = p->x;
	pos->y = p->y;
	if (draw){
		//Draw line from 'old' to 'p'
	}
}

void Turtle::lookAt(PV2D* p){
	dir = (*p - *pos).angle();
}

void Turtle::turnTo(GLdouble a){
	dir += a;
}

void Turtle::forward(GLdouble dist){
	pos->x += dist*cos(dir);
	pos->y += dist*sin(dir);
}
