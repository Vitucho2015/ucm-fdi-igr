/**
	Fichero: Tree.h
	Autor: Xavier Gallofré Nieva

	Clase que define el árbol. Se trata de una representación de árbol binario en un vector,
	que permite recorrer todos los cuadrados linealmente y acceder a los distintos niveles
	del árbol accediendo a las posiciones potencias de dos.
*/

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
	int squareGlowing;
	Color oldColor;

public:
	Tree(void);
	~Tree(void);

	void initTree(Square *square);
	void glow(PV2D *p);

	bool isEmpty();

	PV2D getSupportPoint(Square *square, double alpha);
	void generateChildsFor(int i);
	void generateNewLevel();
	void deleteLastLevel();
	void render();

	void initColors();
};

