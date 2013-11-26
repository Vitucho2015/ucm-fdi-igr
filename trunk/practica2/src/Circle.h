#pragma once
#include "obstacle.h"
#include "RegPol.h"
class Circle :
	public Obstacle//, RegPol
{
private:
	double radius;
	PV2D center;
	RegPol* circle;
	PV2D normal;
public:
	Circle(PV2D* center, double radius);
	~Circle(void);

	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
	void render(bool debug);

	void setColor(RGBColor color){circle->setColor(color);};
};

