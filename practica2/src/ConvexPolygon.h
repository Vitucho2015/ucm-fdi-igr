#pragma once

#include "PV2D.h"
#include <vector>

using namespace std;

class ConvexPolygon
{
private:
	int nSides;
	vector<PV2D*> vertex;
	vector<PV2D*> n;
public:
	ConvexPolygon(void);
	bool cyrusBeck(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn);
};

