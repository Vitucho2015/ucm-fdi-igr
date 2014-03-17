#pragma once

#include <Windows.h>
#include <gl/GL.h>

#include "PV3D.h"
#include "Face.h"

class Mesh
{
protected:
	int numVertex, numFaces, numNormals;
	PV3D** vertex, **normal;
	Face** face;

public:
	Mesh(void);
	~Mesh(void);
	void render();
	PV3D* getNormalVector_Newell(Face* face);

	
};

