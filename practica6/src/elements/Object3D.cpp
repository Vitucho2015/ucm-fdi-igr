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
	glMultMatrixd(mT.m);
}
	
void Object3D::pop(){
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}