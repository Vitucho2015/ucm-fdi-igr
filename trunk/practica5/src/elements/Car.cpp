/**
	Autor: Xavier Gallofré Nieva
*/
#include "Car.h"


Car::Car(int totalSteps){
	this->totalSteps = totalSteps;
	step = 0;
	wheel = new Wheel();
}


Car::~Car(void)
{
}

void Car::render(){
	glPushMatrix();
	float t_i = ((float) step)/totalSteps * 4 * PI;
	
	GLdouble* m = route.getFrenetMatrix(t_i);
	glMultMatrixd(m);

	Mesh::render();

	//Chasis
	glPushMatrix();
		glColor3f(1,1,1);
		glScaled(1,0.4,1);
		glTranslated(0,-0.2,0);
		glutSolidCube(0.5);
	glPopMatrix();

	//Wheels
	glPushMatrix();
		glTranslated(0.25,0,-0.25); wheel->render();
		glTranslated(0,0,0.5);		wheel->render();
		glTranslated(-0.5,0,0);		wheel->render();
		glTranslated(0,0,-0.5);		wheel->render();	
	glPopMatrix();

	//Axis
	/*
	glBegin(GL_LINES);
		glColor3f(1,0,0);	glVertex3d(0,0,0); glVertex3d(1, 0, 0);	// N axis
		glColor3f(0,1,0);	glVertex3d(0,0,0); glVertex3d(0, 1, 0); // B axis
		glColor3f(0,0,1);	glVertex3d(0,0,0); glVertex3d(0, 0, 1);	// T axis
	glEnd();
	*/

	//Head
	glColor3f(1,1,1);
	glTranslated(0,-0.1,0.25);
	glutSolidSphere(0.1,20,20);

	glPopMatrix();
}