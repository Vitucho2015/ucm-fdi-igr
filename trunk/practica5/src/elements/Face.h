#pragma once

#include "PV3D.h"
#include "Pair_VertexNormal.h"

class Face
{
private:
	int numVertex;
	Pair_VertexNormal** arrayVN;

public:
	Face(void);
	~Face(void);

	int getNumVertex(){ return numVertex; };
	Pair_VertexNormal* getVertexNormal(int i){ return arrayVN[i]; };
};

