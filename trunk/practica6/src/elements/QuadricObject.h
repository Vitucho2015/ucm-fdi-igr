#pragma once

#include "Object3D.h"

class QuadricObject : public Object3D {

protected:
	GLUquadricObj* q;

public:
	QuadricObject() { q = gluNewQuadric(); };
	~QuadricObject() { gluDeleteQuadric(q); };

	void setRecoatMode(int i){
		switch(i){
		case 0: gluQuadricDrawStyle(q,GL_POINT); break;
		case 1: gluQuadricDrawStyle(q,GL_LINE); break;
		case 2: gluQuadricDrawStyle(q,GL_FILL); break;
		}
	};

	virtual void draw() = 0;
	
};

