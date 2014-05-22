/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include <vector>

#include "elements\Object3D.h"
#include "elements\CompositeObject.h"
#include "elements\Light.h"

using namespace std;

class Scene : public CompositeObject{
protected:
	vector<Object3D*> objects;
	

public:

	Light* lights[8];

	Scene(void);
	~Scene(void);

	void addObject(Object3D* obj);

	void draw();
	void drawAxis();

	void setRecoatMode(int i);
};

