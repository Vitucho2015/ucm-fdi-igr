/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "mesh.h"
#include "RegularPolygon.h"

class Wheel : public Mesh
{
private: 
	GLdouble rot_z;
public:
	Wheel(void);
	~Wheel(void);

	void render();
	void stepForward(){ rot_z -= 30; if (rot_z > 360) rot_z = 0;};
	void stepBackward(){ rot_z += 30; if (rot_z < 0) rot_z = 360;};
};

