#pragma once

#include "AffineT.h"

class Object3D{

protected:
	
	
	void push();
	void pop();

public:

	AffineT mT;

	Object3D(void);
	~Object3D(void);

	virtual void render() = 0;

};