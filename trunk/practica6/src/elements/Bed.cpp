/**
	Autor: Xavier Gallofré Nieva
*/
#include "Bed.h"

Bed::Bed(GLdouble width,GLdouble height,GLdouble depth, int w_parts,int h_parts,int d_parts){
	
	color.setColor(23.0/255,133.0/255,11.0/255);
	
	Parallelepiped* parallelepiped = new Parallelepiped(width,height,depth,w_parts,h_parts,d_parts);
	addMesh(parallelepiped);
	
}

