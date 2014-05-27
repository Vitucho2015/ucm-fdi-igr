/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include "Object3D.h"

class QuadricObject : public Object3D {

protected:
	GLUquadricObj* q;
	unsigned int texture;

public:
	QuadricObject() { q = gluNewQuadric(); texture = -1;};
	~QuadricObject() { gluDeleteQuadric(q); };

	void setRecoatMode(int i){
		switch(i){
		case 0: gluQuadricDrawStyle(q,GLU_FILL); break;
		case 1: gluQuadricDrawStyle(q,GLU_LINE); break;
		case 2: gluQuadricDrawStyle(q,GLU_POINT); break;		
		}
	};
	
	void setTexture(unsigned int t){ texture = t;};

	virtual void render() = 0;
	
};

