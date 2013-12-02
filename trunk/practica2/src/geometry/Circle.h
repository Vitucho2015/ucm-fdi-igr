#pragma once
#include "ConvexPolygon.h"
#include "Turtle.h"

class Circle : public  ConvexPolygon
{
private:
	double radius;
	PV2D* center;
	PV2D* normalAct; //!!!!!!!!!!

	double bound_radius;
	PV2D* bound_normalAct;
public:
	Circle(PV2D* center, double radius);
	~Circle(void);

	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
	ConvexPolygon* createBoundingBox(double dist);
	void render(bool debug);
};

