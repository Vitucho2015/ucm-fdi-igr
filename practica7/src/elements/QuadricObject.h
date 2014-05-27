/**
	Autor: Xavier Gallofré Nieva
*/
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
		case 0: gluQuadricDrawStyle(q,GLU_FILL); break;
		case 1: gluQuadricDrawStyle(q,GLU_LINE); break;
		case 2: gluQuadricDrawStyle(q,GLU_POINT); break;		
		}
	};
	
	void setTexture(unsigned int t){};

	virtual void render() = 0;
	
};

