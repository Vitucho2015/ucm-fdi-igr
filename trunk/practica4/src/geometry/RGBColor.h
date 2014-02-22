/**
	Fichero: Color.h
	Autor: Xavier Gallofré Nieva
*/

#pragma once
struct RGBColor
{
	double r,g,b;

	RGBColor(void);
	RGBColor(double r, double g, double b);
	//RGBColor(int r, int g, int b);
	~RGBColor(void);

	RGBColor operator+(const RGBColor &o);
	RGBColor operator*(double k);

	RGBColor* weightedMean(double k, RGBColor* color);
	RGBColor* difference(RGBColor* color);
};

