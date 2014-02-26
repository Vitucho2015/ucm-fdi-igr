#include "TextureSaver.h"

#include <stdio.h>

void saveBMPRaw(const char * imagepath, unsigned char * matrix, int width, int height){
	unsigned char header[54];
	for (int i=0;i<54;i++) header[i] = 0;

	header[0] = 'B'; header[1] = 'M';
	*(int*)&(header[0x1A]) = 1;
	*(int*)&(header[0x1E]) = 0;
	*(int*)&(header[0x1C]) = 24;

	*(int*)&(header[0x0A]) = 54;
	*(int*)&(header[0x0E]) = 40;
	*(int*)&(header[0x22]) = 3*width*height;
	*(int*)&(header[0x12]) = width;
	*(int*)&(header[0x16]) = height;

	FILE * file = fopen(imagepath,"w");
	if (!file) {printf("Image could not be opened\n"); return;}

	fwrite(header,1,54,file);
	
	fwrite(matrix,1,3*width*height,file);
	
	fclose(file);
}