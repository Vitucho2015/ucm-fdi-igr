/**
	Autor: Xavier Gallofré Nieva
*/
#include "Face.h"


Face::Face(int numVertex)
{
	this->numVertex = numVertex;
	arrayVN = new Pair_VertexNormal[numVertex];
	for (int i=0;i<numVertex;i++){
		arrayVN[i].vertexIndex = i;
		arrayVN[i].normalIndex = 0;
	}
}


Face::~Face(void)
{
}

Face* Face::clone(){
	Face* ret = new Face(numVertex);
	
	for (int i=0;i<numVertex;i++){
		ret->arrayVN[i].vertexIndex = arrayVN[i].vertexIndex;
		ret->arrayVN[i].normalIndex = arrayVN[i].normalIndex;
	}

	return ret;
}