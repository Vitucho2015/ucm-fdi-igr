/**
	Autor: Xavier Gallofré Nieva
*/
#include "RegularPolygon.h"


RegularPolygon::RegularPolygon(int sides, float radius) : Polygon3D()
{
	float inc = 2*PI/sides;
    for (int i=0;i<sides;i++){
			addVertex(new PV3D(-1*radius*cos(2*PI-i*inc),radius*sin(2*PI-i*inc),0.0));
    }
	close();
}

RegularPolygon::RegularPolygon(int sides, float radius, float start) : Polygon3D()
{
	float inc = 2*PI/sides;
    for (int i=0;i<sides;i++){
			addVertex(new PV3D(-1*radius*cos(start+2*PI-i*inc),radius*sin(start+2*PI-i*inc),0.0));
    }
	close();
}

RegularPolygon::~RegularPolygon(void)
{
}
