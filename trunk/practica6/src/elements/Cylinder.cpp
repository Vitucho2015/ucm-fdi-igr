/**
	Autor: Xavier Gallofré Nieva
*/
#include "Cylinder.h"

void Cylinder::draw(){
	gluCylinder(q,baseRadius,topRadius,height,slices,stacks);
}
