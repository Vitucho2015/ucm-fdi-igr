/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "Mesh.h"
#include "RegularPolygon.h"
#include "Polygon3D.h"
#include "Parallelepiped.h"
#include <GL/freeglut.h>

class Bed : public Mesh {

protected:
	
public:
	Bed(GLdouble width,GLdouble height,GLdouble depth, int w_parts,int h_parts,int d_parts);
	~Bed(void){};

};

