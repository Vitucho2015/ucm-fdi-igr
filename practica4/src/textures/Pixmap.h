#pragma once
#include "../geometry/RGBColor.h"
#include "../geometry/PV2D.h"
#include "TextureLoader.h"

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

class Pixmap
{
public:
	Pixmap(void){}
	Pixmap(int nRows, int nCols, int nChannels);
	Pixmap(const char * imgpath, int nChannels);

	~Pixmap(void);

	void save(int x, int y);
	void load(int x, int y);
	void move(int xIn, int yIn, int xOut, int yOut);
	/*
	void saveBMP();
	*/

	void rotate(double alpha, float centerX, float centerY);

	//Pos: row*nChannels*nCols + col*nChannels -> for (nChannels)
	unsigned char getChannelValue(int channel, int row, int col);
	void setChannelValue(int channel, int row, int col, unsigned char value);
	
	void applyMask5(float mask[]);
	void applyMask9(float mask[]);

	//void applyMask_abs();

protected:
	unsigned char * matrix;
	unsigned int nRows, nCols, nChannels;
};

