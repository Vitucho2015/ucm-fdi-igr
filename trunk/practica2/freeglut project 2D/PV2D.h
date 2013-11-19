/**
	Fichero: PV2D.h
	Autor: Xavier Gallofré Nieva

	Clase para representar y operar con puntos y vectores en 2D
*/

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
	void scale(GLdouble k);
	void nor();
	PV2D normal();
	GLdouble dot(PV2D* o);

	void split(PV2D* n, PV2D*& an, PV2D*& bn);

	PV2D operator+(const PV2D &o);
	PV2D operator-(const PV2D &o);
};

