/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include <math.h>
#include "cylinder.h"
class Spotlight : public Cylinder{
protected:
	GLfloat intensity;

public:
	Spotlight(GLfloat radius, GLfloat height);
	~Spotlight(void){};

	void updateLight();
	void render();

	void scale(GLdouble k);

	void moreIntensity(){ intensity /= 1.1;};
	void lessIntensity(){ intensity *= 1.1;};
};

