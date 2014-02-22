/**
	Fichero: Square.h
	Autor: Xavier Gallofré Nieva

	Clase que define el cuadrado con sus 4 vertices y un color.
*/

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#include "PV2D.h"
#include "RGBColor.h"
#include "Turtle.h"

#define PI 3.14159265

class Square
{
private:
	RGBColor color;
	PV2D vertex[4];
	PV2D normal[4];

public:
	Square(PV2D* v0, PV2D* v1);
	Square(PV2D* center, GLdouble size, GLdouble rad);
	~Square(void);

	PV2D getVertex(int i);
	double getSide();

	RGBColor getColor();
	void setColor(RGBColor color);
	bool isInside(double pX, double pY);
	void render();
};

