#include "PixmapRGB.h"

//Pos: row*nChannels*nCols + col*nChannels
RGBColor* PixmapRGB::getPixel(int row, int col){ 
	if (row < 0 || row > nRows || col < 0 || col > nCols) return new RGBColor();
	int pos = row*nChannels*nCols + col*nChannels;
	return new RGBColor(matrix[pos],matrix[pos+1],matrix[pos+2]);
}
void PixmapRGB::setPixel(int row, int col, RGBColor* color){
	if (row < 0 || row > nRows || col < 0 || col > nCols) return;
	int pos = row*nChannels*nCols + col*nChannels;
	matrix[pos] = ((unsigned char) 255*color->r);
	matrix[pos+1] = ((unsigned char) 255*color->g);
	matrix[pos+2] = ((unsigned char) 255*color->b);
	
}

unsigned char* PixmapRGB::toY(){
	unsigned char* ret = new unsigned char [1*nRows*nCols];
	
	for (int i=0;i<(1*nRows*nCols);i+=3){
			ret[i] = 0.299*matrix[3*i] + 0.587*matrix[3*i+1] + 0.114*matrix[3*i+2];
	}

	return ret;
}

PixmapRGB* PixmapRGB::weightedMean(double k, PixmapRGB* p){

	int maxRows, maxCols;
	maxRows = (this->nRows > p->nRows? this->nRows : p->nRows); 
	maxCols = (this->nCols > p->nCols? this->nCols : p->nCols); 
	PixmapRGB* ret = new PixmapRGB(maxRows,maxCols);

	for (int i=0;i<nRows;i++){
		for (int j=0;j<nCols;j++){
			ret->setPixel(i,j,this->getPixel(i,j)->weightedMean(k,p->getPixel(i,j)));
		}
	}

	return ret;
}

PixmapRGB* PixmapRGB::arithmeticMean(PixmapRGB* p){
	return this->weightedMean(0.5,p);
}

PixmapRGB* PixmapRGB::difference(PixmapRGB* p){
	unsigned char* m1 = this->toY();
	unsigned char* m2 = this->toY();
	return NULL;
}