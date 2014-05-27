/**
	Autor: Xavier Gallofré Nieva
*/
#include "Disk.h"

void Disk::render(){
	push();
	glColor3d(color.r,color.g,color.b);
	if (texture != -1){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,texture);
		gluQuadricTexture(q,true);
	}
	gluDisk(q,innerRadius,outerRadius,slices,rings);
	if (texture != -1) glDisable(GL_TEXTURE_2D);
	pop();
}