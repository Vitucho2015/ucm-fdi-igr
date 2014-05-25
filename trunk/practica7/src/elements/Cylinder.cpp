/**
	Autor: Xavier Gallofré Nieva
*/
#include "Cylinder.h"

Cylinder::Cylinder(GLdouble radius, GLdouble height) : QuadricObject(){
	this->baseRadius = radius;
	this->topRadius = radius;
	this->height = height;
	this->slices = 10;
	this->stacks = 10;
};

Cylinder::Cylinder(GLdouble radius, GLdouble height, int slices, int stacks) : QuadricObject(){
	this->baseRadius = radius;
	this->topRadius = radius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
};

Cylinder::Cylinder(GLdouble baseRadius, GLdouble topRadius, GLdouble height, int slices, int stacks) : QuadricObject(){
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
};

void Cylinder::render(){
	push();
	gluCylinder(q,baseRadius,topRadius,height,slices,stacks);
	pop();
}
