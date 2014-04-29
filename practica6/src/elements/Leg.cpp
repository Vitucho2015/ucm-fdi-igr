#include "Leg.h"

Leg::~Leg(void)
{
}

void Leg::draw(){
	glutSolidCylinder(width,height,10,10);
}