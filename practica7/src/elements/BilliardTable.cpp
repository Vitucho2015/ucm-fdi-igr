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
	bed->mT.translate(0.1,0.05,0.1);
	childs.push_back(bed);
	
	Parallelepiped* parallelepiped;
	width = 0.2;
	height = 0.2;
	depth = 4+0.2;
	
	parallelepiped = new Parallelepiped(width,height,depth,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(0,0,0);
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(width,height,depth,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(2,0,0);
	childs.push_back(parallelepiped);
	
	width = 0.2;
	height = 0.2;
	depth = 1.9;
	
	parallelepiped = new Parallelepiped(width,height,depth,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.rotate(0,90,0);
	parallelepiped->mT.translate(0.2,0,0.2);
	
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(width,height,depth,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.rotate(0,90,0);
	parallelepiped->mT.translate(0.2,0,4.2);
	childs.push_back(parallelepiped);
	
	
	Leg* leg;
	height = 2;
	width = 0.1;
	
	leg = new Leg(width,height);
	leg->mT.translate(0+0.1,0.2,0+0.1);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);	
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(2+0.1,0.2,0+0.1);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(0+0.1,0.2,4+0.1);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(2+0.1,0.2,4+0.1);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(leg);
	
}


BilliardTable::~BilliardTable(void)
{
}
