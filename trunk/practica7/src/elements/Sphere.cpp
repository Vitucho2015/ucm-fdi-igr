/**
	Autor: Xavier Gallofr� Nieva
*/
#include "Sphere.h"


void Sphere::render(){
	push();
	gluSphere(q, radius, slices, stacks);
	pop();
}