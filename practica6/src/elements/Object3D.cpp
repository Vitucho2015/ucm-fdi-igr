#include "Object3D.h"


Object3D::Object3D(void)
{
}


Object3D::~Object3D(void)
{
}


void Object3D::push(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glColor3d(color.r,color.g,color.b);
	glMultMatrixd(mT.m);
}

void Object3D::pop(){
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void Object3D::render(){
	push();
	//Axis
	/*
	glBegin(GL_LINES);
		glColor3f(1,0,0);	glVertex3d(0,0,0); glVertex3d(1, 0, 0);	// N axis
		glColor3f(0,1,0);	glVertex3d(0,0,0); glVertex3d(0, 1, 0); // B axis
		glColor3f(0,0,1);	glVertex3d(0,0,0); glVertex3d(0, 0, 1);	// T axis
	glEnd();
	*/
	draw();
	pop();
}
