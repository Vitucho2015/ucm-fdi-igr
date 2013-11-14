#pragma once

#include "PV2D.h"
#include "Turtle.h"
#include "Color.h"

#define PI 3.14159265

class RegPol
{
private:
	int numOfSides;
	double longOfSide;
	double radius;
	PV2D* vertex;

	Color color;
	PV2D* normal;

public:
	RegPol(PV2D* center, int num, double side);
	~RegPol(void);

	void move(double x, double y);

	void render();
};

