/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "polygon.h"
class RegularPolygon : public Polygon {

public:
	RegularPolygon(int sides, float radius);
	RegularPolygon(int sides, float radius, float start); 
	~RegularPolygon(void);

};

