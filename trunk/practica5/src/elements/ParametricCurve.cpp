#include "ParametricCurve.h"


ParametricCurve::ParametricCurve(void){

}


ParametricCurve::~ParametricCurve(void){

}

PV3D* ParametricCurve::B(float t){
	PV3D* ret;
	PV3D* c1 = Cdiff(t);
	PV3D* c2 = Cdiff2(t);
	ret = c1->cross(c2);
	delete c1; delete c2;
	return ret;
}

PV3D* ParametricCurve::T(float t){
	PV3D* ret;
	ret = Cdiff(t);
	ret->normalize();
	return ret;
}

PV3D* ParametricCurve::N(float t){
	PV3D* ret;
	PV3D* b_ = B(t);
	PV3D* t_ = T(t);
	ret = b_->cross(t_);
	delete b_; delete t_;
	return ret;
}