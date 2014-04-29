#include "Sphere.h"


void Sphere::render(){
	gluSphere(q, radius, slices, stacks);
}