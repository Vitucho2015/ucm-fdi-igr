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
	glColor3d(color.r,color.g,color.b);
	if (texture != -1){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture);
		gluQuadricTexture(q,true);
	}
	gluCylinder(q,baseRadius,topRadius,height,slices,stacks);
	if (texture != -1) glDisable(GL_TEXTURE_2D);
	pop();
}
