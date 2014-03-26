#include "ParametricCurve.h"


ParametricCurve::ParametricCurve(void){}
ParametricCurve::~ParametricCurve(void){}

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

GLdouble* ParametricCurve::getFrenetMatrix(float t_i){
	
	PV3D *n = N(t_i), *b = B(t_i), *t = T(t_i), *c = C(t_i);

	GLdouble* m = new GLdouble[16];
	
	m[0] = n->x;	m[1] = n->y;	m[2] = n->z;	m[3] = 0;
	m[4] = b->x;	m[5] = b->y;	m[6] = b->z;	m[7] = 0;
	m[8] = t->x;	m[9] = t->y;	m[10] = t->z;	m[11] = 0;
	m[12] = c->x;	m[13] = c->y;	m[14] = c->z;	m[15] = 1;
	

	return m;
}