#pragma once

#include "Object3D.h"

class QuadricObject : public Object3D {

protected:
	GLUquadricObj* q;

public:
	QuadricObject() { q = gluNewQuadric(); };
	~QuadricObject() { gluDeleteQuadric(q); };

	virtual void render() = 0;
};

