#pragma once

#include <vector>
#include "PV2D.h"
#include "RGBColor.h"
#include "Obstacle.h"
#include "Turtle.h"

#define SCALE_NORMAL_FACTOR 10


using namespace std;

class ConvexPolygon : public Obstacle
{
protected:
	bool isClosed;
	RGBColor* color;	
	vector<PV2D*> vertex;
	vector<PV2D*> normal;
public:
	ConvexPolygon(void);
	~ConvexPolygon(void);
	
	void setColor(RGBColor* color){this->color = color;};
	int getNSides(){return vertex.size();};

	void addVertex(double x, double y);
	void addVertex(PV2D* p);
	void closePolygon();
	void move(double x, double y);
	void render(bool debug);
	bool collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);//cyrusBeck
	ConvexPolygon* createBoundingBox(double dist);

private:
	vector<PV2D*> createArc(PV2D* center, PV2D* p1, PV2D* p2);
};

