/**
	Autor: Xavier Gallofré Nieva
*/
#include "Sphere.h"


void Sphere::render(){
	push();
	glColor3d(color.r,color.g,color.b);
	if (texture != -1){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture);
		gluQuadricTexture(q,true);
	}
	gluSphere(q, radius, slices, stacks);
	if (texture != -1) glDisable(GL_TEXTURE_2D);
	pop();
}