#include "AffineT.h"


AffineT::AffineT(void)
{
	if (m == NULL) delete m;
	m = new GLdouble[16];
	m[0] = 1; m[4] = 0;	m[8]  = 0; m[12] = 0;
	m[1] = 0; m[5] = 1;	m[9]  = 0; m[13] = 0;
	m[2] = 0; m[6] = 0;	m[10] = 1; m[14] = 0;
	m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;
}

void AffineT::postMultiply(GLdouble* m){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixd(m);
		glMultMatrixd(this->m);
		glGetDoublev(GL_MODELVIEW_MATRIX, this->m);
	glPopMatrix();
}

void AffineT::translate(GLdouble x, GLdouble y, GLdouble z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslated(x,y,z);
		GLdouble* mm = new GLdouble[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiply(mm);
}

void AffineT::scale(GLdouble kx, GLdouble ky, GLdouble kz){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScaled(kx,ky,kz);
		GLdouble* mm = new GLdouble[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiply(mm);
}

void AffineT::scale(GLdouble k){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScaled(k,k,k);
		GLdouble* mm = new GLdouble[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiply(mm);
}

void AffineT::rotate(GLdouble alpha_x, GLdouble alpha_y, GLdouble alpha_z){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotated(alpha_x,1,0,0);
		glRotated(alpha_y,0,1,0);
		glRotated(alpha_z,0,0,1);
		GLdouble* mm = new GLdouble[16];
		glGetDoublev(GL_MODELVIEW_MATRIX, mm);
	glPopMatrix();
	postMultiply(mm);
}