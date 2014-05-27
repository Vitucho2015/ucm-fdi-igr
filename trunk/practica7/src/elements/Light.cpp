/**
	Autor: Xavier Gallofré Nieva
*/
#include "Light.h"


Light::Light(GLenum id)
{
	this->id = id;
	pos = new PV3D(0,0,1);
	local_light = false;
}


Light::~Light(void)
{
}

void Light::update(){
	GLfloat v[] = {pos->x, pos->y, pos->z, local_light? 1 : 0};
	glLightfv(id, GL_POSITION, v);
}