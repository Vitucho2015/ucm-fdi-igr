#pragma once
#include "object3d.h"
#include <GL/freeglut.h>

class Leg : public Object3D {
protected:
	GLdouble height;
	GLdouble width;
public:
	Leg(GLdouble width,GLdouble height){
		this->width = width;
		this->height = height;		
	};
	~Leg(void);

	GLdouble getWidth(){return width;};
	GLdouble getHeight(){return height;};
	
	void draw();
};

