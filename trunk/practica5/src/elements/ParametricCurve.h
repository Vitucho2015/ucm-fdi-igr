/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "PV3D.h"

class ParametricCurve {
public:
	ParametricCurve(void);
	~ParametricCurve(void);

	virtual PV3D* C(float t) = 0;
	virtual PV3D* Cdiff(float t) = 0;
	virtual PV3D* Cdiff2(float t) = 0;

	PV3D* B(float t);
	PV3D* T(float t);
	PV3D* N(float t);

	GLdouble* getFrenetMatrix(float t);
};

