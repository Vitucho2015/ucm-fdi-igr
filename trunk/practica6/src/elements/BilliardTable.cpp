/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardTable.h"


BilliardTable::BilliardTable(void)
{
	GLdouble width,height, depth;
	width = 2;
	height =0.05;
	depth = 4;

	Bed* bed = new Bed(width,height,depth,10,2,20);
	bed->mT.translate(0.1,0,0.1);
	childs.push_back(bed);
	
	Sidebar* sidebar;
	width = 0.2;
	height = 0.2;
	depth = 4;
	
	sidebar = new Sidebar(width,height,depth,0);
	sidebar->mT.translate(0,height/2,0);
	childs.push_back(sidebar);
	
	sidebar = new Sidebar(width,height,depth,0);
	sidebar->mT.translate(depth/2,height/2,0);
	childs.push_back(sidebar);
	
	width = 0.2;
	height = 0.2;
	depth = 2;

	sidebar = new Sidebar(width,height,depth,90);
	sidebar->mT.translate(0,height/2,-0.2);
	sidebar->mT.rotate(0,90,0);
	childs.push_back(sidebar);

	sidebar = new Sidebar(width,height,depth,90);
	sidebar->mT.translate(0,height/2,2*depth);
	childs.push_back(sidebar);
	
	
	Leg* leg;
	height = 2;
	width = 0.1;

	leg = new Leg(width,height);
	leg->mT.translate(0,0.2,0);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);	
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(2,0.2,0);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(0,0.2,4);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(2,0.2,4);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
}


BilliardTable::~BilliardTable(void)
{
}
