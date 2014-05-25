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
	
public:

	Light* lights[8];

	Scene(void);
	~Scene(void);

	void setRecoatMode(int i);
};

