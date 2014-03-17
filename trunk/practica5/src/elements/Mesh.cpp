#include "Mesh.h"


Mesh::Mesh(void)
{
}


Mesh::~Mesh(void)
{
}

void Mesh::render(){
	for (int i=0; i<numFaces;i++){
		glLineWidth(1.0);
		glBegin(GL_POLYGON);
		for (int j=0; j<face[i]->getNumVertex(); j++) {
			int iN = face[i]->getVertexNormal(j)->normalIndex;
			int iV = face[i]->getVertexNormal(j)->vertexIndex;
			glNormal3f(normal[iN]->x, normal[iN]->y, normal[iN]->z);
			//Texture Coords Here (j index) with glTexCoor2f
			glVertex3f(vertex[iV]->x, vertex[iV]->y, vertex[iV]->z);
		}
		glEnd();
	}
}


PV3D* Mesh::getNormalVector_Newell(Face* face){
	PV3D* n = new PV3D();
	PV3D *currVertex, *nextVertex;
	for (int i=0;i<numVertex;i++){
		currVertex = vertex[face->getVertexNormal(i)->vertexIndex];
		nextVertex = vertex[face->getVertexNormal((i+1)%face->getNumVertex())->vertexIndex];
		n->x += (currVertex->y - nextVertex->y) * (currVertex->z + nextVertex->z);
		n->y += (currVertex->z - nextVertex->z) * (currVertex->x + nextVertex->x);
		n->z += (currVertex->x - nextVertex->x) * (currVertex->y + nextVertex->y);
	}
	n->normalize();
	return n;
}