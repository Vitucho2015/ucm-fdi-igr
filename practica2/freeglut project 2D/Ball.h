#pragma once

#include "PV2D.h"
#include "Circle.h"
class Ball
{
private:
	double radius;
	PV2D center;
	PV2D vel;
	RegPol* circle;

public:
	Ball(PV2D* center, double radius);
	~Ball(void);

	void step();
	void render();

	void setVel(PV2D* vel);
};

