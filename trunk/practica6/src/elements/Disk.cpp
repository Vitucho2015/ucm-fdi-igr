#include "Disk.h"

void Disk::render(){
	gluDisk(q,innerRadius,outerRadius,slices,rings);
}