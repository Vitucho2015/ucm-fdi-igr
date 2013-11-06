/**
	Fichero: Scene.h
	Autor: Xavier Gallofré Nieva

	Clase que contiene los datos del Area Visible de la Escena, los datos del árbol que vamos a representar
	y los métodos necesarios para explorar la escena.
*/

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
	
	void initTree(Square *square);
	void glow(PV2D *p);
	void newLevel();
	void retrieveLevel();

	bool isEmpty();

	void render();
};

