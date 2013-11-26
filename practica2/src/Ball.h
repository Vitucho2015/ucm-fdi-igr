#pragma once

#include "PV2D.h"
#include "Circle.h"

class Ball
{
private:
	double radius;
	PV2D center;
	PV2D vel;
	PV2D v1; //normalize
	RegPol* circle;

public:
	Ball(PV2D* center, double radius);
	~Ball(void);
	void step(double t);
	void bounce(PV2D* normal);
	void render(bool debug);

	void setVel(PV2D* vel){this->vel = *vel; v1 = this->vel; v1.nor();};
	PV2D* getVel(){return &vel;};
	PV2D* getV1(){return &v1;};
	PV2D* getCenter(){return &center;};
	double getRadius(){return radius;};
	void setColor(RGBColor color){this->circle->setColor(color);};
};

