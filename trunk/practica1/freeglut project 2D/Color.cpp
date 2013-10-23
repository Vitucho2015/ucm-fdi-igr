#include "Color.h"


Color::Color(void)
{
	r = 0;
	g = 0;
	b = 0;
}


Color::Color(double r, double g, double b){
	this->r = r/255;
	this->g = g/255;
	this->b = b/255;
}

Color::~Color(void)
{
}
