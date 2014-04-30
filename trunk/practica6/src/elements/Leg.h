/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "object3d.h"
#include "Cylinder.h"
#include <GL/freeglut.h>

class Leg : public Cylinder {
protected:
	GLdouble height;
	GLdouble width;
public:
	Leg(GLdouble width,GLdouble height);
	~Leg(void){};

	GLdouble getWidth(){return width;};
	GLdouble getHeight(){return height;};
	
};

