#pragma once

#include <vector>

#include "elements\Object3D.h"

using namespace std;

class Scene : public Object3D{
protected:
	vector<Object3D*> objects;

public:
	Scene(void);
	~Scene(void);

	void addObject(Object3D* obj);

	void draw();
	void drawAxis();
};

