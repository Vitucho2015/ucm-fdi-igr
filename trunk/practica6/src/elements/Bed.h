#pragma once
#include "object3d.h"
#include <GL/freeglut.h>

class Bed : public Object3D {

protected:
	GLdouble width;
	GLdouble height;
	GLdouble depth;

public:
	Bed(GLdouble width,GLdouble height,GLdouble depth){
		this->width = width;
		this->height = height;
		this->depth = depth;
	};
	~Bed(void);

	void draw();
};

