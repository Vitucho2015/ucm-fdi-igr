#pragma once
#include "quadricobject.h"
class Sphere : public QuadricObject {

protected:
	GLdouble radius;
	int slices;
	int stacks;

public:
	Sphere(GLdouble radius) : QuadricObject(){
		this->radius = radius;
		this->slices = 10;
		this->stacks = 10;
	};
	
	Sphere(GLdouble radius,int slices,int stacks) : QuadricObject(){
		this->radius = radius;
		this->slices = slices;
		this->stacks = stacks;
	};
	~Sphere(void){};

	void render();
};

