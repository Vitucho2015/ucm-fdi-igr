#pragma once

#include "PV2D.h"
#include "Turtle.h"
#include "RGBColor.h"
#include "ConvexPolygon.h"

class RegPol : public ConvexPolygon
{
	
public:
	RegPol(PV2D* center, int num, double side);
	
};

