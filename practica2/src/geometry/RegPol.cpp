#include "RegPol.h"


RegPol::RegPol(PV2D* center, int num, double side)
{
	Turtle *turtle = new Turtle(center);
	
	double alpha = 2.0*PI/num;
	double beta = (PI-alpha)/2.0;
	
	double radius = side/(2.0*sin(alpha/2));

	turtle->forward(radius);
	addVertex(new PV2D(turtle->getPosition()));
	
	turtle->turnTo(PI-beta);
	for (int i=1;i<num;i++){
		turtle->forward(side);
		addVertex(new PV2D(turtle->getPosition()));
		turtle->turnTo(PI- 2*beta);
	}
	delete turtle;

	closePolygon();
}
