#include "Leg.h"

Leg::Leg(GLdouble width,GLdouble height) : Cylinder(width,width,height,10,10) {
	this->width = width;
	this->height = height;		
	mT.rotate(90,0,0);
}

