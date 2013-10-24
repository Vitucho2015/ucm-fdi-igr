#pragma once

#include <vector>
#include <cmath>

#include "Square.h"


using namespace std;

class Tree
{
private:
	vector<Color> colors; 
	vector<Square> squares; // length: 2^levels
	int lastLevel;

public:
	Tree(void);
	~Tree(void);

	void initTree(Square *square);

	PV2D getSupportPoint(Square *square, double alpha);
	void generateChildsFor(int i);
	void generateNewLevel();
	void deleteLastLevel();
	void render();

	void initColors();
};

