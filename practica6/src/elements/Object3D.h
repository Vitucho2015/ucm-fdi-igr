#pragma once

#include "AffineT.h"

class Object3D{

protected:
	AffineT mT;
	
	void push();
	void pop();

public:
	Object3D(void);
	~Object3D(void);

	virtual void render() = 0;

};