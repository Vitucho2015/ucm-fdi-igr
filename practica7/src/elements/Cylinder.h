/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "quadricobject.h"
class Cylinder : public QuadricObject {
protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble height;
	int slices;
	int stacks;

public:
	Cylinder(GLdouble radius, GLdouble height) : QuadricObject(){
		this->baseRadius = radius;
		this->topRadius = radius;
		this->height = height;
		this->slices = 10;
		this->stacks = 10;
	};

	Cylinder(GLdouble radius, GLdouble height, int slices, int stacks) : QuadricObject(){
		this->baseRadius = radius;
		this->topRadius = radius;
		this->height = height;
		this->slices = slices;
		this->stacks = stacks;
	};

	Cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, int slices, int stacks) : QuadricObject(){
		this->baseRadius = baseRadius;
		this->topRadius = topRadius;
		this->height = height;
		this->slices = slices;
		this->stacks = stacks;
	};
	~Cylinder(void){};

	void draw();
};

