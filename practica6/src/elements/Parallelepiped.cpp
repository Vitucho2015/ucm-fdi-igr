/**
	Autor: Xavier Gallofr� Nieva
*/
#include "Parallelepiped.h"


Parallelepiped::Parallelepiped(GLdouble width,GLdouble height,GLdouble depth,int w_parts,int h_parts,int d_parts)
{
	
	GLdouble inc_width = width/w_parts;
	GLdouble inc_height = height/h_parts;
	GLdouble inc_depth = depth/d_parts;
	
	Polygon3D* pol;
	Mesh* block;
	
	/*
	PV3D** x = new PV3D*[w_parts-1];
	PV3D** y = new PV3D*[h_parts-1];
	PV3D** z = new PV3D*[d_parts-1];

	pol = new Polygon3D();
	pol->addVertex(new PV3D(0,0,0));
	pol->addVertex(new PV3D(0,height,0));
	pol->addVertex(new PV3D(width,height,0));
	pol->addVertex(new PV3D(width,0,0));
	pol->close();
	addMesh(pol->extrude(new PV3D(0,0,depth)));
	*/

	
	for (int i=0;i<w_parts;i++){
		for (int j=0;j<h_parts;j++){
			for (int k=0;k<d_parts;k++){
				
				pol = new Polygon3D();
				pol->addVertex(new PV3D(0,0,0));
				pol->addVertex(new PV3D(0,inc_height,0));
				pol->addVertex(new PV3D(inc_width,inc_height,0));
				pol->addVertex(new PV3D(inc_width,0,0));
	
				pol->close();

				block = pol->extrude(new PV3D(0,0,-inc_depth));
				block->translate(new PV3D(0,0,inc_depth));
				pol->translate(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				block->translate(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				addMesh(pol);
				addMesh(block);

				pol = new Polygon3D();
				pol->addVertex(new PV3D(0,0,inc_depth));
				pol->addVertex(new PV3D(inc_width,0,inc_depth));
				pol->addVertex(new PV3D(inc_width,inc_height,inc_depth));
				pol->addVertex(new PV3D(0,inc_height,inc_depth));
		
				pol->close();
				pol->translate(new PV3D(i*inc_width,j*inc_height,k*inc_depth));
				addMesh(pol);
			}			
		}
	}
}


Parallelepiped::~Parallelepiped(void)
{
}
