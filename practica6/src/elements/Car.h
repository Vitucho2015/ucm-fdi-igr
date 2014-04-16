/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "mesh.h"
#include "CurveP5.h"
#include "Wheel.h"
#include "CurveCirc.h"

#include <GL/freeglut.h>

class Car : public Object3D {

private:
	CurveP5 route;
	//CurveCirc route;
	Wheel* wheel;
	int step, totalSteps;
	
public:
	Car(int totalSteps);
	~Car(void);
	void render();
	void stepForward(){ step++; if (step == totalSteps) step = 0; wheel->stepForward();};
	void stepBackward(){ step--; if (step == 0) step = totalSteps; wheel->stepBackward();};
};

