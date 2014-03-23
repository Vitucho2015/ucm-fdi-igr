#include "RegularPolygon.h"


RegularPolygon::RegularPolygon(int sides, float radius) : Polygon()
{
	float inc = 2*PI/sides;
    for (int i=0;i<sides;i++){
			addVertex(new PV3D(radius*cos(2*PI-i*inc),radius*sin(2*PI-i*inc),0.0));
    }
	close();
}


RegularPolygon::~RegularPolygon(void)
{
}
