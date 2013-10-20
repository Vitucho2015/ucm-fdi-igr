#pragma once

#include "PV2D.h"
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

class Turtle
{
private:
	PV2D *pos;
	GLdouble dir;

public:
	Turtle(void);
	Turtle(PV2D* pos);
	~Turtle(void);

	PV2D getPosition();
	GLdouble getDir();

	void moveTo(PV2D* p, bool draw);
	void lookAt(PV2D* p);
	void turnTo(GLdouble a);
	void forward(GLdouble dist);

};

