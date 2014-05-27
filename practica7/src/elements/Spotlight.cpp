/**
	Autor: Xavier Gallofré Nieva
*/
#include "Spotlight.h"


Spotlight::Spotlight(GLfloat radius, GLfloat height) : Cylinder(radius,0,height,10,10){

	color = RGBColor(0.3,0.5,0.7);
	mT.translate(radius,-radius,0);
	mT.rotate(-90,0,0);
	intensity = 40.0;
}

void Spotlight::updateLight(){
	
	GLfloat pos[]={0,0,height,1};
	GLfloat dir[]={0.0,0.0,-1.0,0.0};
	GLfloat a1[]={0.0, 0.0, 0.0, 1};
	GLfloat d1[]={1.0, 1.0, 1.0, 1};
	GLfloat s1[]={1.0, 1.0, 1.0, 1};
	GLfloat alpha = atan2(baseRadius,height);
	alpha = alpha * 360.0 / (2*3.141592);

	glLightfv(GL_LIGHT1, GL_POSITION, pos);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);

	glLightfv(GL_LIGHT1, GL_AMBIENT, a1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, d1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, s1);
	
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, alpha);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, intensity);
	
}

void Spotlight::scale(GLdouble k){
	height *= k;
	updateLight();
}

void Spotlight::render(){
	push();
	gluCylinder(q,baseRadius,topRadius,height,slices,stacks);
	updateLight();
	pop();
}