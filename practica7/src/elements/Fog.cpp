/**
	Autor: Xavier Gallofré Nieva
*/
#include "Fog.h"


Fog::Fog(GLint start, GLint end, GLfloat density){
	this->start = start;
	this->end = end;
	this->density = density;
	color = RGBColor(1,1,1);
}

void Fog::update(){
	glFogi(GL_FOG_START, start);
	glFogi(GL_FOG_END, end);
	glFogf(GL_FOG_DENSITY, density);
	GLfloat fogColor[] = {color.b, color.g, color.r,1};
	glFogfv(GL_FOG_COLOR, fogColor);
}

void Fog::on(){ glEnable(GL_FOG);}
void Fog::off(){ glDisable(GL_FOG);}
