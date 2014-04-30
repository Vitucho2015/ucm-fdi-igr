#include "Sphere.h"


void Sphere::draw(){
	gluSphere(q, radius, slices, stacks);
}