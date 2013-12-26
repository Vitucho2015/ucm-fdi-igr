#pragma once

#include "PV2D.h"

class Obstacle{
public:
	virtual void move(double x, double y) = 0;
	virtual void render(bool debug) = 0;

	virtual bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn) = 0;
	virtual Obstacle* createBoundingBox(double dist) = 0;
	
};