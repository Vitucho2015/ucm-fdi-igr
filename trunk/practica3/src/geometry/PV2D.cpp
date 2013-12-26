/**
	Fichero: PV2D.cpp
	Autor: Xavier Gallofré Nieva

	Clase para representar y operar con puntos y vectores en 2D
*/

#include "PV2D.h"


PV2D::PV2D(void)
{
	x = 0;
	y = 0;
}


PV2D::PV2D(GLdouble x, GLdouble y)
{
	this->x = x;
	this->y = y;
}

GLdouble PV2D::mod() {
	return sqrt(x*x+y*y);
}

GLdouble PV2D::angle() {
	return atan2(y,x);
}

void PV2D::nor() {
	scale(1.0/mod());
}

PV2D PV2D::normal(){
	PV2D ret(-this->y, this->x);
	ret.nor();
	return ret;
}

GLdouble PV2D::dot(PV2D* o){
	return this->x * o->x + this->y * o->y;
}

void PV2D::translate(GLdouble x, GLdouble y){
	this->x += x;
	this->y += y;
}

void PV2D::scale(GLdouble k){
	this->x *= k;
	this->y *= k;
}

void PV2D::scale(GLdouble kx, GLdouble ky){
	this->x *= kx;
	this->y *= ky;
}

void PV2D::rotate(GLdouble alpha){
	x = x*cos(alpha) - y*sin(alpha);
	y = x*sin(alpha) + y*cos(alpha);
}

void PV2D::split(PV2D* n, PV2D*& an, PV2D*& bn){
	PV2D n_izq = n->normal();
	double a,b;
	a = this->dot(n)/n->dot(n);
	b = this->dot(&n_izq)/n_izq.dot(&n_izq);
 	an = new PV2D(*n);
	an->scale(a);
	bn = new PV2D(n_izq);
	bn->scale(b);
}

PV2D PV2D::operator+(const PV2D &o) {
	PV2D result = *this;
	result.x += o.x;
	result.y += o.y;
	return result;
}

PV2D PV2D::operator-(const PV2D &o) {
	return PV2D(this->x - o.x, this->y - o.y);
}
