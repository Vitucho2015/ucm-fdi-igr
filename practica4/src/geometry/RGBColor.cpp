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

RGBColor RGBColor::operator+(const RGBColor &o){
	RGBColor result(o);
	result.weightedMean(0.5, this);
	return result;
}


RGBColor RGBColor::operator*(double k){
	RGBColor* ret = new RGBColor();
	ret->r = this->r * k;
	ret->g = this->g * k;
	ret->b = this->b * k;
	return *ret;
}

RGBColor* RGBColor::weightedMean(double k, RGBColor* color){
	RGBColor* ret = new RGBColor();
	ret->r = k*this->r + (1-k)*color->r;
	ret->g = k*this->g + (1-k)*color->g;
	ret->b = k*this->b + (1-k)*color->b;
	return ret;
}

RGBColor* RGBColor::difference(RGBColor* color){
	RGBColor* ret = new RGBColor();
	ret->r = this->r - color->r; if (ret->r < 0) ret->r = -ret->r;
	ret->g = this->g - color->g; if (ret->g < 0) ret->g = -ret->g;
	ret->b = this->b - color->b; if (ret->b < 0) ret->b = -ret->b;
	return ret;
}