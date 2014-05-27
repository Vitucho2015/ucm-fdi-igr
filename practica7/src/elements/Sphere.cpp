/**
	Autor: Xavier Gallofré Nieva
*/
#include "Sphere.h"


void Sphere::render(){
	push();
	glColor3d(color.r,color.g,color.b);
	gluSphere(q, radius, slices, stacks);
	pop();
}