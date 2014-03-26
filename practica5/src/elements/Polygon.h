#pragma once
#include "Mesh.h"
class Polygon : public Mesh {

protected:
	bool isClosed;

public:
	Polygon(void);
	~Polygon(void);

	void addVertex(PV3D* v);
	void close();

	Mesh* extrude(PV3D* dir);
	Mesh* extrude(Polygon* p);
	Mesh* extrude(Polygon* p, bool divCenter);
	
};

