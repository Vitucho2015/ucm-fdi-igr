/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "CompositeObject.h"
#include "Bed.h"
#include "Leg.h"
#include "Parallelepiped.h"
#include "../textures/PixmapRGB.h"

class BilliardTable : public CompositeObject {
protected: 
	GLdouble w_leg,h_leg;
	GLdouble w_bed,d_bed,h_bed;
	GLdouble w_wood;

	unsigned int texture[2];

public:
	BilliardTable(void);
	~BilliardTable(void);

	GLdouble getHeight(){return h_leg+w_wood/2+h_bed/2;};
};

