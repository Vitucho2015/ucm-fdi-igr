/**
	Autor: Xavier Gallofré Nieva
*/
#include "CurveCirc.h"

PV3D* CurveCirc::C(float t){
	return new PV3D(5*cos(t),0,5*sin(t));
}

PV3D* CurveCirc::Cdiff(float t){
	return new PV3D(-5*sin(t),0,5*cos(t));
}

PV3D* CurveCirc::Cdiff2(float t){
	return new PV3D(-5*cos(t),0,-5*sin(t));
}
