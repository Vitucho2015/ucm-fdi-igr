#pragma once
#include "Obstacle.h"
#include "Color.h"
class Triangle : public Obstacle
{
private:
	Color color;
	PV2D vertex[3];
	PV2D normal[3];
public:
	Triangle(PV2D* p1,PV2D* p2,PV2D* p3);
	~Triangle(void);

	bool intersectionLine2Triangle (PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
	void render();
};

