/**
	Autor: Xavier Gallofré Nieva
*/
#include "Balls.h"


Balls::Balls(void)
{
	GLdouble r = 0.05;
	RGBColor c(0.7,0.4,0.5);
	Ball* b;
	
	RGBColor cs[] = {
		RGBColor(1,0.6,0),
		RGBColor(0.5,0,1),
		RGBColor(1,0.6,0),
		RGBColor(0,0.4,1),
		RGBColor(1,0.3,0),
		RGBColor(0,0.5,0),
		RGBColor(1,0.3,0),
		RGBColor(0,0.4,1),
		RGBColor(1,0.3,0),
		RGBColor(1,220.0/255,0),
		RGBColor(0,0,0),
		RGBColor(160.0/255,30.0/255,60.0/255),
		RGBColor(0.5,0,1),
		RGBColor(160.0/255,30.0/255,60.0/255),
		RGBColor(1,220.0/255,0)
	};

	GLdouble offX = 0,offY = 0;
	GLdouble inc = 2.5*r;
	int nc = 0;
	for (int i=0;i<5;i++){
		offY = inc*i;
		offX = i*inc/2;
		for (int j=i;j<5;j++){
			b = new Ball(r);
			b->color.setColor(cs[nc++]);
			b->mT.translate(r+offX,r,r+offY);
			childs.push_back(b);		
			offX += inc;
		}
	}
	
}

