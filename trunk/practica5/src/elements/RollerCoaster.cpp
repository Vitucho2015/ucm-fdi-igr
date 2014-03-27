/**
	Autor: Xavier Gallofr� Nieva
*/
#include "RollerCoaster.h"

/**
* NP: N�mero de lados del pol�gono que aproxima la circunferencia del tubo
* NQ: N�mero de rodajas que forman el tubo
*/
RollerCoaster::RollerCoaster(int np, int nq) : Mesh() {
	CurveP5 curve;
	int radius = 1;
	//CurveCirc curve;
	float t_i = 0;
	PV3D *n, *b, *t, *c; 
	RegularPolygon *first = new RegularPolygon(np,radius);
	n = curve.N(t_i); b = curve.B(t_i);
	t = curve.T(t_i); c = curve.C(t_i);
	vector<PV3D*> vertex_ = first->getVertex();
	for (PV3D* v : vertex_){
		float x,y,z;
		x = n->x * v->x + b->x * v->y + t->x * v->z + c->x;
		y = n->y * v->x + b->y * v->y + t->y * v->z + c->y;
		z = n->z * v->x + b->z * v->y + t->z * v->z + c->z;
		v->x = x; v->y = y; v->z = z;
	}
	this->addMesh(first);
	RegularPolygon *slice;
	RegularPolygon *prev = first;
	for (int i=0;i<nq;i++){
		t_i = i* 4.0*PI/nq;
		n = curve.N(t_i); b = curve.B(t_i);
		t = curve.T(t_i); c = curve.C(t_i);
		slice = new RegularPolygon(np,radius);
		vector<PV3D*> vertex_ = slice->getVertex();
		for (PV3D* v : vertex_){
			float x,y,z;
			x = n->x * v->x + b->x * v->y + t->x * v->z + c->x;
			y = n->y * v->x + b->y * v->y + t->y * v->z + c->y;
			z = n->z * v->x + b->z * v->y + t->z * v->z + c->z;
			v->x = x; v->y = y; v->z = z;
		}
		//this->addMesh(prev->extrude(slice));
		//this->addMesh(prev->extrude(slice, false));
		this->addMesh(prev->extrude(slice, true));
		
		//this->addMesh(slice);
		prev = slice;
	}
	//this->addMesh(prev->extrude(first));
	//this->addMesh(prev->extrude(first, false));
	this->addMesh(prev->extrude(first, true));
	
}


RollerCoaster::~RollerCoaster(void)
{
}
