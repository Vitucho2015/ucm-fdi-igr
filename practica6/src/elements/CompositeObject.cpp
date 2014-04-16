#include "CompositeObject.h"


CompositeObject::CompositeObject(void)
{
}


CompositeObject::~CompositeObject(void)
{
}

void CompositeObject::render(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixd(mT.m);
		for (Object3D* o : childs) o->render();
	glPopMatrix();

}