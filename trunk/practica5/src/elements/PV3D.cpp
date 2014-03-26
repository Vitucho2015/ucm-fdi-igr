/**
	Autor: Xavier Gallofré Nieva
*/
#include "PV3D.h"


PV3D::PV3D(void) {
	x = 0; y = 0; z = 0;
}

PV3D::PV3D(GLdouble x, GLdouble y, GLdouble z) {
	this->x = x; this->y = y; this->z = z;
}

PV3D::~PV3D(void)
{
}

void PV3D::normalize() {
	scale(1.0/mod());
}
	
GLdouble PV3D::mod(){
	return sqrt(x*x+y*y+z*z);
}

void PV3D::scale(GLdouble k){
	this->x *= k;
	this->y *= k;
	this->z *= k;
}

void PV3D::scale(GLdouble kx, GLdouble ky, GLdouble kz){
	this->x *= kx;
	this->y *= ky;
	this->z *= kz;
}

GLdouble PV3D::angle(PV3D* v){
	GLdouble cos_tv = this->dot(v);
	cos_tv = cos_tv / (this->mod() * v->mod());
	cos_tv = cosh(cos_tv) / (2*PI) * 360.0;
	return cos_tv;
}

GLdouble PV3D::dot(PV3D* v){
	return this->x * v->x + this->y * v->y + this->z * v->z;
}

PV3D* PV3D::cross(PV3D* v){

	PV3D* ret = new PV3D();
	ret->x = this->y * v->z - this->z * v->y;
	ret->y = this->z * v->x - this->x * v->z;
	ret->z = this->x * v->y - this->y * v->x;
	ret->normalize();
	return ret;

}

PV3D* PV3D::clone(){ return new PV3D(x,y,z); }