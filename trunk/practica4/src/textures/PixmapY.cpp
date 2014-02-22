#include "PixmapY.h"

//Pos: row*nChannels*nCols + col*nChannels
RGBColor* PixmapY::getPixel(int row, int col){
	if (row < 0 || row > nRows || col < 0 || col > nCols) return NULL;
	int pos = row*nChannels*nCols + col*nChannels;
	return new RGBColor(matrix[pos]/255,matrix[pos]/255,matrix[pos]/255);
}
void PixmapY::setPixel(int row, int col, RGBColor* color){
	if (row < 0 || row > nRows || col < 0 || col > nCols) return;
	int pos = row*nChannels*nCols + col*nChannels;
	matrix[pos] = color->r*255;
}
