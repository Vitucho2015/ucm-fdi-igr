/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "parametriccurve.h"
class CurveP5 : public ParametricCurve {

public:
	CurveP5(void){};
	~CurveP5(void){};

	PV3D* C(float t);
	PV3D* Cdiff(float t);
	PV3D* Cdiff2(float t);
};

