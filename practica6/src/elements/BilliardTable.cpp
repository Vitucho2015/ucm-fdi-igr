#include "BilliardTable.h"


BilliardTable::BilliardTable(void)
{
	Bed* bed = new Bed();

	childs.push_back(bed);

	Leg* leg;
	
	leg = new Leg();
	leg->mT.translate(0,1,0);
	childs.push_back(leg);
	
	leg = new Leg();
	leg->mT.translate(0,1,0);
	childs.push_back(leg);
	
	leg = new Leg();
	leg->mT.translate(0,1,0);
	childs.push_back(leg);
	
	leg = new Leg();
	leg->mT.translate(0,1,0);
	childs.push_back(leg);
	
}


BilliardTable::~BilliardTable(void)
{
}
