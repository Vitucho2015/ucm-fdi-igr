#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#include "PV2D.h"
#include "Turtle.h"

#define PI 3.14159265

class Square
{
private:
	double color_r, color_g, color_b;
	PV2D vertex[4];

public:
	Square(void);
	Square(PV2D* v0, PV2D* v1);
	Square(PV2D* center, GLdouble size, GLdouble rad);
	~Square(void);

	PV2D getVertex(int i);
	double getSide();

	void render();
};

