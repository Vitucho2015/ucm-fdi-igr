/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include <math.h>
#include "cylinder.h"
class Spotlight : public Cylinder{
public:
	Spotlight(GLfloat radius, GLfloat height);
	~Spotlight(void){};

	void updateLight();
	void render();

	void scale(GLdouble k);
};

