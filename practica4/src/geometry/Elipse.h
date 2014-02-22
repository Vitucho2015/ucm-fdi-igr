#pragma once
#include "Circle.h"

class Elipse : public Circle
{
private:
	double width, height;

public:
	Elipse(PV2D* center, double width, double height);
	~Elipse(void);

	void render(bool debug);
	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
	ConvexPolygon* createBoundingBox(double dist);
};

