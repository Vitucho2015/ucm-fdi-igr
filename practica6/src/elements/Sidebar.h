/**
	Autor: Xavier Gallofr� Nieva
*/
#pragma once
#include "mesh.h"
#include "RegularPolygon.h"

class Sidebar :
	public Mesh
{

public:
	Sidebar(GLdouble width,GLdouble height,GLdouble depth, GLdouble degrees);
	~Sidebar(void);
};

