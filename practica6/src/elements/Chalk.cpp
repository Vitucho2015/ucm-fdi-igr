#include "Chalk.h"


Chalk::Chalk(GLdouble width){
	
	Mesh* chalk_base = new Mesh();
	chalk_base->setRender_Filled(true);
	
	chalk_base->mT.translate(0.5,0.5,0);
	chalk_base->mT.scale(width,width,width);	
	//mT.translate(width/2,width/2,0);		
	
	chalk_base->color.setColor(0.5,0.25,0);
	
	RegularPolygon* rp = new RegularPolygon(4,sqrt(2)/2,PI/4);
	chalk_base->addMesh(rp);
	RegularPolygon* rp2 = new RegularPolygon(4,sqrt(2)/2,PI/4);
	rp2->translate(new PV3D(0,0,0.75));
	chalk_base->addMesh(rp->extrude(rp2));
	
	childs.push_back(chalk_base);

	Mesh* chalk = new Mesh();
	chalk->setRender_Filled(true);
	chalk->color.setColor(0,0.5,0.5);
	chalk->mT.translate(0.5,0.5,0);
	chalk->mT.scale(width,width,width);
	chalk->addMesh(rp2->extrude(new PV3D(0,0,0.25)));

	RegularPolygon* rp3 = new RegularPolygon(4,1.0/2,PI/4);
	rp3->translate(new PV3D(0,0,0.72));
	chalk->addMesh(rp3->extrude(rp2));
	chalk->addMesh(rp3);
	childs.push_back(chalk);

}

