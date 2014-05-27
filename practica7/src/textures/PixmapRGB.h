/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "pixmap.h"

class PixmapRGB :
public Pixmap
{
public:
	PixmapRGB(int nRows, int nCols) : Pixmap(nRows,nCols,3){};
	PixmapRGB(const char * imgpath) : Pixmap(imgpath,3){};

	RGBColor* getPixel(int row, int col);
	void setPixel(int row, int col, RGBColor* color);

	PixmapRGB* weightedMean(double k, PixmapRGB* p);
	PixmapRGB* arithmeticMean(PixmapRGB* p);
	PixmapRGB* difference(PixmapRGB* p);

	unsigned char* toY();
};

