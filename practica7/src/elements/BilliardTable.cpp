/**
	Autor: Xavier Gallofré Nieva
*/
#include "BilliardTable.h"


BilliardTable::BilliardTable(void)
{


	PixmapRGB* textures[2];
	
	textures[0] = new PixmapRGB("../wood.bmp");
	textures[1] = new PixmapRGB("../baize2.bmp");

	
	glGenTextures(2, texture);
	
	glBindTexture(GL_TEXTURE_2D, texture[0]); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textures[0]->getCols(), textures[0]->getRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, textures[0]->getMatrix());
	

	glBindTexture(GL_TEXTURE_2D, texture[1]); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textures[1]->getCols(), textures[1]->getRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, textures[1]->getMatrix());
	
	w_bed = 2;
	d_bed = 4;
	h_bed = 0.05;

	w_leg = 0.1;
	h_leg = 2;
	
	w_wood = 0.2;
	
	mT.translate(0,h_leg,0);

	Bed* bed = new Bed(w_bed,h_bed,d_bed,20,1,40);
	bed->mT.translate(w_wood,w_wood/2-h_bed/2,w_wood);
	bed->setTexture(texture[1]);
	childs.push_back(bed);
	
	
	Parallelepiped* parallelepiped;	
	parallelepiped = new Parallelepiped(w_wood,w_wood,d_bed+2*w_wood,2,2,20);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->setTexture(texture[0]);
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(w_wood,w_wood,d_bed+2*w_wood,2,2,20);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood+w_bed,0,0);
	parallelepiped->setTexture(texture[0]);
	childs.push_back(parallelepiped);
		
	parallelepiped = new Parallelepiped(w_bed,w_wood,w_wood,10,2,2);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood,0,0);	
	parallelepiped->setTexture(texture[0]);
	childs.push_back(parallelepiped);
	
	parallelepiped = new Parallelepiped(w_bed,w_wood,w_wood,10,2,2);
	parallelepiped->color.setColor(133.0/255,82.0/255,11.0/255);
	parallelepiped->mT.translate(w_wood,0,w_wood+d_bed);
	parallelepiped->setTexture(texture[0]);
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
