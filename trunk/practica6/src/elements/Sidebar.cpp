/**
	Autor: Xavier Gallofré Nieva
*/
#include "Sidebar.h"


Sidebar::Sidebar(GLdouble width,GLdouble height,GLdouble depth, GLdouble degrees)
{
	//setRender_Filled(true);

	Polygon3D* pol = new Polygon3D();
	pol->addVertex(new PV3D(0,0,0));
	pol->addVertex(new PV3D(0,height,0));
	pol->addVertex(new PV3D(width,height,0));
	pol->addVertex(new PV3D(width,0,0));
	
	pol->close();

	Mesh* block = pol->extrude(new PV3D(0,0,depth));
	addMesh(block);

	color.setColor(23.0/255,133.0/255,11.0/255);
	/*
	RegularPolygon* rp = new RegularPolygon(4,sqrt(2)/2,PI/4);
	addMesh(rp);
	RegularPolygon* rp2 = new RegularPolygon(4,sqrt(2)/2,PI/4);
	rp2->translate(new PV3D(0,0,1));
	addMesh(rp->extrude(rp2));
	addMesh(rp);
	addMesh(rp2);
	*/
	color.setColor(133.0/255,82.0/255,11.0/255);
}


Sidebar::~Sidebar(void)
{
}
