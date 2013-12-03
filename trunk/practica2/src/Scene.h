/**
	Fichero: Scene.h
	Autor: Xavier Gallofré Nieva

	Clase que contiene los datos del Area Visible de la Escena, los datos del árbol que vamos a representar
	y los métodos necesarios para explorar la escena.
*/

#pragma once

#include <vector>
#include "geometry\Triangle.h"
#include "geometry\Circle.h"
#include "Ball.h"
#include <time.h>

using namespace std;

class Scene
{
private:
	
	//static System::Windows::Forms::Timer^ myTimer = gcnew System::Windows::Forms::Timer;

	vector<Obstacle*> obstacles;
	vector<Obstacle*> b_obstacles;
	Ball* ball;
	bool bb_active;

public:
	Scene(void);
	~Scene(void);

	double xL,xR,yT,yB;

	void move(int dir, double percent);
	void zoom(double factor);
	
	bool isEmpty();

	void step();
	void render(bool debug, bool debug_ball);

	void initBall();
	void initScene(int i);

	void activeBB(bool bb){bb_active = bb;};
};

