#pragma once

#include <vector>

#include "Square.h"

using namespace std;

class Tree
{
private:
	vector<Square> squares;
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
};

