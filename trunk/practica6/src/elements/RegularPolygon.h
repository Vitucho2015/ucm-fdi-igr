/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "polygon3D.h"
class RegularPolygon : public Polygon3D {

public:
	RegularPolygon(int sides, float radius);
	RegularPolygon(int sides, float radius, float start); 
	~RegularPolygon(void);

};

