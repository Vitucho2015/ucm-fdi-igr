#include "Cylinder.h"

void Cylinder::render(){
	gluCylinder(q,baseRadius,topRadius,height,slices,stacks);
}
