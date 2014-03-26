/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "parametriccurve.h"
class CurveCirc : public ParametricCurve {
public:
	CurveCirc(void){};
	~CurveCirc(void){};

	PV3D* C(float t);
	PV3D* Cdiff(float t);
	PV3D* Cdiff2(float t);
};

