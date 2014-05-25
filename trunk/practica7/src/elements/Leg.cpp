/**
	Autor: Xavier Gallofré Nieva
*/
#include "Leg.h"

Leg::Leg(GLdouble width,GLdouble height) : Cylinder(width,height,10,10) {
	this->width = width;
	this->height = height;		
	mT.translate(width,width,0);	
	mT.rotate(90,0,0);
}

