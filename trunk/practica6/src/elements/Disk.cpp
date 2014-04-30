/**
	Autor: Xavier Gallofré Nieva
*/
#include "Disk.h"

void Disk::draw(){
	gluDisk(q,innerRadius,outerRadius,slices,rings);
}