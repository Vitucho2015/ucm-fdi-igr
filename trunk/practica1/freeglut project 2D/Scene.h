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
	//void progressiveZoom(double factor, double nIter);

	//void tilling(int nCols);
	void initTree(Square *square);
	void newLevel();
	void retrieveLevel();

	//PV2D convertPV2SVA(int x, int y);

	void render();
};

