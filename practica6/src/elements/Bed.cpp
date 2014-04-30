#include "Bed.h"

Bed::Bed(GLdouble width,GLdouble height,GLdouble depth, int w_parts,int h_parts,int d_parts){
	
	setRender_Filled(true);
	
	mT.scale(width,height,depth);	
	mT.translate(1,height,0);		
	color.setColor(23.0/255,133.0/255,11.0/255);
	
	RegularPolygon *rp, *rp2;
	
	for (int i=0;i<w_parts;i++){
		
		for (int j=0;j<h_parts;j++){
			
			for (int k=0;k<d_parts;k++){

			}
		}
	}
	/*
	RegularPolygon* rp = new RegularPolygon(4,sqrt(2)/2,PI/4);
	addMesh(rp);
	RegularPolygon* rp2 = new RegularPolygon(4,sqrt(2)/2,PI/4);
	rp2->translate(new PV3D(0,0,1));
	addMesh(rp->extrude(rp2));
	addMesh(rp2);
	*/
}

