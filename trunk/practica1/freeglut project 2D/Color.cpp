#include "Color.h"


Color::Color(void)
{
	r = 0;
	g = 0;
	b = 0;
}


Color::Color(double r, double g, double b){
	this->r = r;
	this->g = g;
	this->b = b;
}

Color::~Color(void)
{
}
