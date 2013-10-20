#pragma once

#include "Tree.h"

class Scene
{
private:
	
	Tree *tree;
public:
	Scene(void);
	~Scene(void);

double xL,xR,yT,yB;

	void move(int dir, double percent);
	void zoom(double factor);

	void newLevel();

	void render();
};

