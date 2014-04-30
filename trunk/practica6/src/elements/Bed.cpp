/**
	Autor: Xavier Gallofré Nieva
*/
#include "Bed.h"

Bed::Bed(GLdouble width,GLdouble height,GLdouble depth, int w_parts,int h_parts,int d_parts){
	
	setRender_Filled(true);
	
	//mT.scale(width,height,depth);	
	//mT.translate(1,height,0);		
	color.setColor(23.0/255,133.0/255,11.0/255);
	
	//RegularPolygon *rp, *rp2;
	
	Polygon3D *pol = new Polygon3D();

	GLdouble inc_width = width/w_parts;
	GLdouble inc_height = height/h_parts;
	GLdouble inc_depth = depth/d_parts;
	/*
	pol = new Polygon3D();
	pol->addVertex(new PV3D(0,0,0));
	pol->addVertex(new PV3D(0,inc_height,0));
	pol->addVertex(new PV3D(inc_width,inc_height,0));
	pol->addVertex(new PV3D(inc_width,0,0));
	pol->close();
	Mesh* block = pol->extrude(new PV3D(0,0,inc_depth));
	*/
	//addMesh(block);
	/*
	block = pol->extrude(new PV3D(0,0,inc_depth));
	block->translate(new PV3D(0*inc_width,0*inc_height,0*inc_depth));
	addMesh(block);

	block = pol->extrude(new PV3D(0,0,inc_depth));
	block->translate(new PV3D(1*inc_width,0*inc_height,0*inc_depth));
	addMesh(pol);
	addMesh(block);
	*/
	for (int i=0;i<w_parts;i++){
		for (int j=0;j<h_parts;j++){
			for (int k=0;k<d_parts;k++){
				Sidebar* sidebar = new Sidebar(inc_width,inc_height,inc_depth,0);
				sidebar->translate(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				addMesh(sidebar);
				/*
				block = pol->extrude(new PV3D(0,0,inc_depth));
				block->translate(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				addMesh(block);
				*/
				/*
				pol = new Polygon3D();
				pol->addVertex(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				pol->addVertex(new PV3D(i*inc_width,(j+1)*inc_height,k*inc_depth));
				pol->addVertex(new PV3D((i+1)*inc_width,(j+1)*inc_height,k*inc_depth));
				pol->addVertex(new PV3D((i+1)*inc_width,j*inc_height,k*inc_depth));
				pol->close();
				Mesh* block = pol->extrude(new PV3D(0,0,inc_depth));
				addMesh(block);
				*/
			}			
		}
	}
	
	/*

	rp = new RegularPolygon(4,sqrt(2)/2,PI/4);
	addMesh(rp);
	rp2 = new RegularPolygon(4,sqrt(2)/2,PI/4);
	rp2->translate(new PV3D(0,0,1));
	addMesh(rp->extrude(rp2));
	addMesh(rp2);
	*/
}

