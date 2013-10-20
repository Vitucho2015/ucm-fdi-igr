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

PV2D PV2D::operator+(const PV2D &o) {
	PV2D result = *this;
	result.x += o.x;
	result.y += o.y;
	return result;
}

PV2D PV2D::operator-(const PV2D &o) {
	return PV2D(this->x - o.x, this->y - o.y);
}