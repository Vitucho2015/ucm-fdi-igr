/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "AffineT.h"
#include "RGBColor.h"

class Object3D{

protected:
	
	void push();
	void pop();

public:

	AffineT mT;
	RGBColor color;

	Object3D(void);
	~Object3D(void);

	virtual void render() = 0;
	void drawAxis();
	virtual void setRecoatMode(int i) = 0;
};