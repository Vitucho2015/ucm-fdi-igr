#include "CurveP5.h"

PV3D* CurveP5::C(float t){
	return new PV3D(3*cos(t),2*cos(1.5*t),3*sin(t));
}

PV3D* CurveP5::Cdiff(float t){
	return new PV3D(-3*sin(t),-3*sin(1.5*t),3*cos(t));
}

PV3D* CurveP5::Cdiff2(float t){
	return new PV3D(-3*cos(t),-4.5*cos(1.5*t),-3*sin(t));
}