/**
	Autor: Xavier Gallofré Nieva
*/
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

unsigned char* PixmapY::toRGB(){
	unsigned char* ret = new unsigned char [3*nRows*nCols];

	for (int i=0;i<(1*nRows*nCols);i++){
			ret[3*i] = matrix[i];
			ret[3*i+1] = matrix[i]; 
			ret[3*i+2] = matrix[i];
	}

	return ret;
}

PixmapY* PixmapY::difference(PixmapY* p){
	int maxRows, maxCols;
	maxRows = (this->nRows > p->nRows? this->nRows : p->nRows); 
	maxCols = (this->nCols > p->nCols? this->nCols : p->nCols); 
	PixmapY* ret = new PixmapY(maxRows,maxCols);

	unsigned char value;
	for (int i=0;i<nRows;i++){
		for (int j=0;j<nCols;j++){
			value = this->getChannelValue(0,i,j) - p->getChannelValue(0,i,j);
			if (value < 0) value = -value;
			ret->setChannelValue(0,i,j,value);
		}
	}

	return ret;
}

void PixmapY::sobel(int umbral){
	float mask_gX[] = {1,0,-1,2,0,-2,1,0,-1};
	float mask_gY[] = {1,2,1,0,0,0,-1,-2,-1};
	
	unsigned char* backup = getMatrix();

	applyFilter9(mask_gX);
	unsigned char* Gx = getMatrix();
	setMatrix(backup);
	applyFilter9(mask_gY);
	unsigned char* Gy = getMatrix();

	int n = nRows*nCols;
	unsigned char* res = new unsigned char[n];
	for (int i=0;i<n;i++){
		if (Gx[i] < 0) Gx[i] = -Gx[i];
		if (Gy[i] < 0) Gy[i] = -Gy[i];
		if (Gx[i] + Gy[i] > umbral) res[i] = 255; else res[i] = 0;
	}
	setMatrix(res);
}