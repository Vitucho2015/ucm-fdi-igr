#include "Pixmap.h"


Pixmap::Pixmap(int nRows, int nCols, int nChannels){
	this->nRows = nRows;
	this->nCols = nCols;
	this->nChannels = nChannels;
	matrix = new unsigned char [nChannels*nRows*nCols];
}

Pixmap::Pixmap(const char * imgpath, int nChannels){
	this->nChannels = nChannels;
	matrix = loadBMPRaw(imgpath,nCols,nRows,false);
}

Pixmap::~Pixmap(void){
	delete matrix;
}

void Pixmap::save(int x, int y){
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(x,y,nCols,nRows, GL_BGR_EXT, GL_UNSIGNED_BYTE, matrix);
}

void Pixmap::load(int x, int y){
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2i(x,y);
	glDrawPixels(nCols,nRows, GL_BGR_EXT, GL_UNSIGNED_BYTE, matrix);
}

void Pixmap::move(int xIn, int yIn, int xOut, int yOut){
	glRasterPos2i(xOut, yOut);
	glCopyPixels(xIn, yIn, nCols, nRows, GL_COLOR);
}

unsigned char Pixmap::getChannelValue(int channel, int row, int col){ 
	if (channel < 0 || channel >= nChannels) return 0; 
	if (row < 0 || row >= nRows || col < 0 || col >= nCols) return 0;
	int pos = row*nChannels*nCols + col*nChannels + channel;
	return matrix[pos];
}

void Pixmap::setChannelValue(int channel, int row, int col, unsigned char value){
	if (channel < 0 || channel >= nChannels) return; 
	if (row < 0 || row >= nRows || col < 0 || col >= nCols) return;
	int pos = row*nChannels*nCols + col*nChannels + channel;
	matrix[pos] = value;
}

void Pixmap::rotate(double alpha, float centerX, float centerY){
	Pixmap pix_tmp(this->nRows, this->nCols, this->nChannels);
	PV2D rot;
	for (int ch=0;ch<nChannels;ch++){
		for (int u=0;u<nRows;u++){
			for (int v=0;v<nCols;v++){
				rot.x = u-centerX;
				rot.y = v-centerY;
				rot.rotate(-alpha);
				float x = centerX + rot.x;
				float y = centerY + rot.y;
			
				int i = (int) x; 
				int j = (int) y;
				float diffX = x - i;
				float diffY = y - j;
				unsigned char tmp = getChannelValue(ch,i,j)*(1.0-diffX)*(1.0-diffY) + getChannelValue(ch,i,j+1)*(1.0-diffX)*diffY + getChannelValue(ch,i+1,j+1)*diffX*diffY + getChannelValue(ch,i+1,j)*diffX*(1.0-diffY);
				pix_tmp.setChannelValue(ch,u,v,tmp);
			
			}
		}
	}
	for (int ch=0;ch<nChannels;ch++){
		for (int u=0;u<nCols;u++){
			for (int v=0;v<nRows;v++){
				setChannelValue(ch,u,v,pix_tmp.getChannelValue(ch,u,v));
			}
		}
	}
}

void Pixmap::applyMask5(float mask[]){
	float weight = 0;
	for (int i=0;i<4;i++) weight += mask[i];
	float mask9[] = {
		0,			mask[0],	0,
		mask[1],	mask[2],	mask[3],
		0,			mask[4],	0,
	};
	this->applyMask9(mask9);
	
}

void Pixmap::applyMask9(float mask[]){
	Pixmap pix_tmp(this->nRows, this->nCols, this->nChannels);

	float weight = 0;
	for (int i=0;i<9;i++) weight += mask[i];

	float tmp;
	for (int ch=0;ch<nChannels;ch++){
		for (int i=0;i<nRows;i++){
			for (int j=0;j<nCols;j++){
				tmp = 0;
				tmp += mask[0]*getChannelValue(ch,i-1,j-1);
				tmp += mask[1]*getChannelValue(ch,i-1,j);
				tmp += mask[2]*getChannelValue(ch,i-1,j+1);
				tmp += mask[3]*getChannelValue(ch,i,j-1);
				tmp += mask[4]*getChannelValue(ch,i,j);
				tmp += mask[5]*getChannelValue(ch,i,j+1);
				tmp += mask[6]*getChannelValue(ch,i+1,j-1);
				tmp += mask[7]*getChannelValue(ch,i+1,j);
				tmp += mask[8]*getChannelValue(ch,i+1,j+1);
				tmp = tmp/weight;
				pix_tmp.setChannelValue(ch,i,j,(unsigned char) tmp);
			}
		}
	}

	for (int ch=0;ch<nChannels;ch++){
		for (int u=0;u<nCols;u++){
			for (int v=0;v<nRows;v++){
				setChannelValue(ch,u,v,pix_tmp.getChannelValue(ch,u,v));
			}
		}
	}
}



//void Pixmap::applyMask_mode(){}
//void Pixmap::applyMask_median(){}
//void Pixmap::applyMask_max(){}
//void Pixmap::applyMask_min(){}