#pragma once
#include "mesh.h"
#include "Wheel.h"
class Car :
	public Mesh
{
private:
	Wheel* wheel;
public:
	Car(void);
	~Car(void);
};

