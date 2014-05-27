/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "mesh.h"
#include "RegularPolygon.h"

class Parallelepiped : public Mesh {

public:
	Parallelepiped(GLdouble width,GLdouble height,GLdouble depth, int w_parts,int h_parts,int d_parts);
	~Parallelepiped(void);

};

