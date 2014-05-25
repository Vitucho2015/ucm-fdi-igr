/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardTable.h"


BilliardTable::BilliardTable(void)
{
	w_bed = 2;
	d_bed = 4;
	h_bed = 0.05;

	w_leg = 0.1;
	h_leg = 2;
	
	w_wood = 0.2;
	
	mT.translate(0,h_leg,0);

	Bed* bed = new Bed(w_bed,h_bed,d_bed,10,2,20);
	bed->mT.translate(w_wood,w_wood/2-h_bed/2,w_wood);
	childs.push_back(bed);
	
	Parallelepiped* parallelepiped;	
	parallelepiped = new Parallelepiped(w_wood,w_wood,d_bed+2*w_wood,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(w_wood,w_wood,d_bed+2*w_wood,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood+w_bed,0,0);
	childs.push_back(parallelepiped);
		
	parallelepiped = new Parallelepiped(w_bed,w_wood,w_wood,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood,0,0);	
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(w_bed,w_wood,w_wood,2,2,10);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood,0,w_wood+d_bed);
	childs.push_back(parallelepiped);
	
	Leg* leg;
	
	leg = new Leg(w_leg,h_leg);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);	
	childs.push_back(leg);
	
	leg = new Leg(w_leg,h_leg);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	leg->mT.translate(w_wood+w_bed,0,0);	
	childs.push_back(leg);
	
	leg = new Leg(w_leg,h_leg);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	leg->mT.translate(0,0,w_wood+d_bed);	
	childs.push_back(leg);
	
	leg = new Leg(w_leg,h_leg);
	leg->color.setColor(133.0/255,82.0/255,11.0/255);
	leg->mT.translate(w_wood+w_bed,0,w_wood+d_bed);	
	childs.push_back(leg);
	
}


BilliardTable::~BilliardTable(void)
{
}
