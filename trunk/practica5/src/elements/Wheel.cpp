#include "Wheel.h"


Wheel::Wheel(void){
	RegularPolygon* hubcap = new RegularPolygon(30,1);
	hubcap->translate(new PV3D(0,0,-0.25));
	this->addMesh(hubcap);
	this->addMesh(hubcap->extrude(new PV3D(0,0,0.5)));
	hubcap->translate(new PV3D(0,0,0.5));
	this->addMesh(hubcap);
	delete hubcap;
	render_filled = true;
	rot_z = 0.0;
}

Wheel::~Wheel(void) {}

void Wheel::render(){
	glPushMatrix();
	glRotated(90,0,1,0);
	glRotated(rot_z,0,0,1);
	glScaled(0.125, 0.125, 0.125);
	glColor3f(1,1,1);
	
	Mesh::render();
	
	glColor3f(1,0,1);
	glBegin(GL_LINES);
		glVertex3d(vertex[0]->x, vertex[0]->y, vertex[0]->z);
		glVertex3d(vertex[0]->x, vertex[0]->y, vertex[0]->z + 8);
	glEnd();

	glPopMatrix();
}