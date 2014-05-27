/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "RGBColor.h"

class Fog
{
protected:
	GLint start,end;
	GLfloat density;
	RGBColor color;

public:
	Fog(GLint start, GLint end, GLfloat density);
	~Fog(void){};

	void update();

	void on();
	void off();

	void setStart(GLint start){ this->start = start;};
	void setEnd(GLint end){ this->end = end;};
	void setDensity(GLfloat density){ this->density = density;};
	void setColor(RGBColor color){ this->color = color;};

	void mode_Linear(){ glFogi(GL_FOG_MODE, GL_LINEAR);};
	void mode_Exp(){ glFogi(GL_FOG_MODE, GL_EXP);};
	void mode_Gaussian(){ glFogi(GL_FOG_MODE, GL_EXP2);};
};

