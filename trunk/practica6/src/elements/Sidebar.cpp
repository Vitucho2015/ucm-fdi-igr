#include "Sidebar.h"


Sidebar::Sidebar(GLdouble width,GLdouble height,GLdouble depth, GLdouble degrees)
{
	setRender_Filled(true);
	mT.scale(width,height,depth);
	mT.rotate(0,degrees,0);
	
	
	
	color.setColor(23.0/255,133.0/255,11.0/255);
	RegularPolygon* rp = new RegularPolygon(4,sqrt(2)/2,PI/4);
	addMesh(rp);
	RegularPolygon* rp2 = new RegularPolygon(4,sqrt(2)/2,PI/4);
	rp2->translate(new PV3D(0,0,1));
	addMesh(rp->extrude(rp2));
	addMesh(rp);
	addMesh(rp2);

	color.setColor(133.0/255,82.0/255,11.0/255);
}


Sidebar::~Sidebar(void)
{
}
