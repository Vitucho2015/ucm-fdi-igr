#pragma once
#include "Obstacle.h"
#include "RGBColor.h"


class Triangle : public Obstacle
{
private:
	RGBColor color;
	PV2D vertex[3];
	PV2D normal[3];
public:
	Triangle(PV2D* p1,PV2D* p2,PV2D* p3);
	~Triangle(void);

	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
	void render(bool debug);

	void setColor(RGBColor color){this->color = color;};
};

