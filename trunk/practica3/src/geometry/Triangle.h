#pragma once
#include "Obstacle.h"
#include "RGBColor.h"
#include "ConvexPolygon.h"

class Triangle : public ConvexPolygon
{
public:
	Triangle(PV2D* p1,PV2D* p2,PV2D* p3);

	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
};

