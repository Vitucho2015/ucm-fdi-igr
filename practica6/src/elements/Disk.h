#pragma once
#include "quadricobject.h"
class Disk :
	public QuadricObject
{
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
	int slices;
	int rings;
	GLdouble startAngle;
	GLdouble sweepAngle;

public:
	Disk(GLdouble innerRadius, GLdouble outerRadius, int slices, int rings, GLdouble startAngle, GLdouble sweepAngle) : QuadricObject() {
		this->innerRadius = innerRadius;
		this->outerRadius = outerRadius;
		this->slices = slices;
		this->rings = rings;
		this->startAngle = startAngle;
		this->sweepAngle = sweepAngle;
	};
	~Disk(void);

	void render();
};

