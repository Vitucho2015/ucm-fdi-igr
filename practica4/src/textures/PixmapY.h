#pragma once
#include "pixmap.h"
class PixmapY :
public Pixmap
{
public:
	PixmapY(int nRows, int nCols) : Pixmap(nRows,nCols,1){};
	PixmapY(const char * imgpath) : Pixmap(imgpath,1){};

	RGBColor* getPixel(int row, int col);
	void setPixel(int row, int col, RGBColor* color);
};

