/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "Mesh.h"
class Polygon3D : public Mesh {

protected:
	bool isClosed;

public:
	Polygon3D(void);
	~Polygon3D(void);

	void addVertex(PV3D* v);
	void close();

	Mesh* extrude(PV3D* dir);
	Mesh* extrude(Polygon3D* p);
	Mesh* extrude(Polygon3D* p, bool divCenter);
	
};

