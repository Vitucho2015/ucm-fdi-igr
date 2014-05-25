/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "quadricobject.h"
class Cylinder : public QuadricObject {
protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble height;
	int slices;
	int stacks;

public:
	Cylinder(GLdouble radius, GLdouble height);
	Cylinder(GLdouble radius, GLdouble height, int slices, int stacks);
	Cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, int slices, int stacks);
	~Cylinder(void){};

	void render();
};

