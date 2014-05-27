/**
	Autor: Xavier Gallofré Nieva
*/
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


void Object3D::drawAxis(){
	
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

}