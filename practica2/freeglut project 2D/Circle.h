#pragma once
#include "obstacle.h"
#include "RegPol.h"
class Circle :
	public Obstacle//, RegPol
{
	
public:
	Circle(PV2D* center, double radius);
	~Circle(void);

};

