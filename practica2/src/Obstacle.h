#pragma once

#include "PV2D.h"

class Obstacle{
public:
	virtual bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn) = 0;
	virtual void render(bool debug) = 0;
};