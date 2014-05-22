/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "AffineT.h"
#include "RGBColor.h"

class Object3D{

protected:
	
	void push();
	virtual void draw() = 0;
	void pop();

public:

	AffineT mT;
	RGBColor color;

	Object3D(void);
	~Object3D(void);

	void render();
	virtual void setRecoatMode(int i) = 0;
};