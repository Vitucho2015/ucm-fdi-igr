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
#include "geometry\Elipse.h"
#include "geometry\RegPol.h"
#include "geometry\ConvexPolygon.h"
#include "textures\PixmapRGB.h"

#include "geometry\Tree.h"

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
	bool showingP3;
	

	double rot;

public:
	Scene(void);
	~Scene(void);

	double xL,xR,yT,yB;

	
	PixmapRGB* pixmap;
	PixmapRGB* pixmap2, *pixmap3;
	
	void move(int dir, double percent);
	void zoom(double factor);
	
	bool isEmpty();

	void step();
	void render(bool debug, bool debug_ball);

	void initBall();
	void initScene(int i);

	float* gaussianMask(int m, float delta);

	void activeBB(bool bb){bb_active = bb;};
	void showP3(bool b){showingP3 = b;};
};

