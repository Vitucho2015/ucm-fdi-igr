/**
	Autor: Xavier Gallofré Nieva
*/
#include "Disk.h"

void Disk::render(){
	push();
	gluDisk(q,innerRadius,outerRadius,slices,rings);
	pop();
}