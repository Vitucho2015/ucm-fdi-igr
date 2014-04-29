#include "BilliardTable.h"


BilliardTable::BilliardTable(void)
{
	GLdouble width,height, depth;
	width = 2;
	height = 0.2;
	depth = 4;

	Bed* bed = new Bed(width,height,depth);
	bed->mT.translate(width/2,0,depth/2);
	childs.push_back(bed);

	Leg* leg;
	height = 2;
	width = 0.1;

	leg = new Leg(width,height);
	leg->mT.translate(1-width,-height,2-width);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(-1+width,-height,2-width);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(-1+width,-height,-2+width);
	childs.push_back(leg);
	
	leg = new Leg(width,height);
	leg->mT.translate(1-width,-height,-2+width);
	childs.push_back(leg);
	
}


BilliardTable::~BilliardTable(void)
{
}
