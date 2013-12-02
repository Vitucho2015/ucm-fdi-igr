/**
	Fichero: Color.cpp
	Autor: Xavier Gallofré Nieva
*/


#include "RGBColor.h"


RGBColor::RGBColor(void)
{
	r = 0;
	g = 0;
	b = 0;
}


RGBColor::RGBColor(double r, double g, double b){
	this->r = r/255;
	this->g = g/255;
	this->b = b/255;
}

RGBColor::~RGBColor(void)
{
}
