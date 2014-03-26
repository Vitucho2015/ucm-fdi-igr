/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "PV3D.h"
#include "Pair_VertexNormal.h"

class Face
{
private:
	int numVertex;
	Pair_VertexNormal* arrayVN;

public:
	Face(int numVertex);
	~Face(void);
	Face* clone();

	int getNumVertex(){ return numVertex; };
	Pair_VertexNormal getVertexNormal(int i){ return arrayVN[i]; };

	void setVertex(int i, int pos_v){ arrayVN[i].vertexIndex = pos_v; };
	void setNormal(int i, int pos_n){ arrayVN[i].normalIndex = pos_n; };
	void setNormal(int pos_n){ for (int i=0;i<numVertex;i++) arrayVN[i].normalIndex = pos_n;};
};

