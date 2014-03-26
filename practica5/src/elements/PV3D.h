#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#define PI 3.14159265
#define EPSILON 0.000000001

struct PV3D
{
	GLdouble x, y, z;
	int pv;

	PV3D();
	PV3D(GLdouble x, GLdouble y, GLdouble z);
	~PV3D(void);
	PV3D* clone();
	
	void normalize();
	GLdouble mod();
	void scale(GLdouble k);
	void scale(GLdouble kx, GLdouble ky, GLdouble kz);
	
	//angles
	GLdouble angle(PV3D* v);


	GLdouble dot(PV3D* v);
	PV3D* cross(PV3D* v);

	void plus(PV3D* v){ x += v->x; y += v->y; z += v->z; }
	void minus(PV3D* v){ x -= v->x; y -= v->y; z -= v->z; }
};

