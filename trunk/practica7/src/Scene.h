/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include <vector>

#include "elements\Object3D.h"
#include "elements\CompositeObject.h"
#include "elements\Light.h"
#include "elements\Fog.h"
#include "textures\PixmapRGB.h"

using namespace std;

class Scene : public CompositeObject{

public:

	Light* lights[8];
	Fog* fog;

	Scene(void);
	~Scene(void);

	void setRecoatMode(int i);

	virtual void setup_fog() = 0;
	virtual void setup_lights() = 0;

	void render();
};

