/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "Object3D.h"

#include <vector>

using namespace std;

class CompositeObject : public Object3D {

protected:

	vector<Object3D*> childs;

public:
	CompositeObject(void);
	~CompositeObject(void);

	void render();	
	void draw(){};
	void setRecoatMode(int i);
};

