/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

struct AffineT{

	GLdouble* m;

	AffineT();
	AffineT(GLdouble* m){ this->m = m; };
	~AffineT(void){ delete m; m = NULL; }

	void postMultiply(GLdouble* m);

	void translate(GLdouble x, GLdouble y, GLdouble z);
	void scale(GLdouble kx, GLdouble ky, GLdouble kz);
	void scale(GLdouble k);
	void rotate(GLdouble alpha_x, GLdouble alpha_y, GLdouble alpha_z);

	GLfloat* getPos();
};

