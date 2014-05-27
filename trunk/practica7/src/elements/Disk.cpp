/**
	Autor: Xavier Gallofré Nieva
*/
#include "Disk.h"

void Disk::render(){
	push();
	glColor3d(color.r,color.g,color.b);
	gluDisk(q,innerRadius,outerRadius,slices,rings);
	pop();
}