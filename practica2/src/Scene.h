/**
	Fichero: Scene.h
	Autor: Xavier Gallofré Nieva

	Clase que contiene los datos del Area Visible de la Escena, los datos del árbol que vamos a representar
	y los métodos necesarios para explorar la escena.
*/

#pragma once

#include <vector>
#include "Triangle.h"
#include "Ball.h"
#include <time.h>

using namespace std;

class Scene
{
private:
	
	//static System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;

	vector<Obstacle*> obstacles;
	Ball* ball;

public:
	Scene(void);
	~Scene(void);

	double xL,xR,yT,yB;

	void move(int dir, double percent);
	void zoom(double factor);
	
	bool isEmpty();

	void step();
	void render(bool debug);

	void initBall();
	void initScene(int i);
};

