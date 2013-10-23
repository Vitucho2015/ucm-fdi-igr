#pragma once

#include <vector>

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
	Tree(Square *square);
	~Tree(void);

	PV2D getSupportPoint(Square *square, double alpha);
	void generateChildsFor(int i);
	void generateNewLevel();
	void deleteLastLevel();
	void render();

	void initColors();
};

