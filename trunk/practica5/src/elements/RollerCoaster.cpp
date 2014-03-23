#include "RollerCoaster.h"

#include <iostream>
/**
* NP: Número de lados del polígono que aproxima la circunferencia del tubo
* NQ: Número de rodajas que forman el tubo
*/
RollerCoaster::RollerCoaster(int np, int nq) : Mesh() {
	CurveP5 curve;
	float t_i;
	PV3D *n, *b, *t, *c; 
	RegularPolygon *slice = new RegularPolygon(np,1);
	RegularPolygon *prev = slice;
	//this->addMesh(slice);
	for (int i=1;i<nq;i++){
		t_i = i* 2.0*PI/nq;
		std::cout << t_i << std::endl;
		n = curve.N(t_i); b = curve.B(t_i);
		t = curve.T(t_i); c = curve.C(t_i);
		slice = new RegularPolygon(np,1);
		vector<PV3D*> vertex_ = slice->getVertex();
		for (PV3D* v : vertex_){
			float x,y,z;
			x = n->x * v->x + b->x * v->y + t->x * v->z + c->x;
			y = n->y * v->x + b->y * v->y + t->y * v->z + c->y;
			z = n->z * v->x + b->z * v->y + t->z * v->z + c->z;
			v->x = x; v->y = y; v->z = z;
		}
		this->addMesh(prev->extrude(slice));
		prev = slice;
	}
	slice = new RegularPolygon(np,1);
	this->addMesh(prev->extrude(slice));
}


RollerCoaster::~RollerCoaster(void)
{
}
