#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

struct PV2D
{
	GLdouble x, y;
	
	PV2D(void);
	PV2D(GLdouble x, GLdouble y);
	
	GLdouble mod();
	GLdouble angle();

	PV2D operator+(const PV2D &o);
	PV2D operator-(const PV2D &o);
};

