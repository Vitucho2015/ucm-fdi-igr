/**
	Autor: Xavier Gallofr� Nieva
*/
#include "Disk.h"

void Disk::draw(){
	gluDisk(q,innerRadius,outerRadius,slices,rings);
}