#include "Bed.h"


Bed::~Bed(void)
{
}

void Bed::draw(){
	glutSolidCube(width);
}