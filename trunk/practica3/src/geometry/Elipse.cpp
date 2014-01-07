#include "Elipse.h"


Elipse::Elipse(PV2D* center, double width, double height) : Circle(center,1)
{
	this->width = width;
	this->height = height;
}


Elipse::~Elipse(void)
{

}

void Elipse::render(bool debug){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslated(center->x, center->y, 0);
	glScaled(width,height,1);
	ConvexPolygon::render(debug);
	glPopMatrix();
}

bool Elipse::collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){
	bool ret;
	PV2D p_tmp = PV2D(*p);
	PV2D v_tmp = PV2D(*v);
	p_tmp.translate(-center->x, -center->y);
	//v_tmp.translate(-center->x, -center->y);
	p_tmp.scale(1.0/width,1.0/height);
	v_tmp.scale(1.0/width,1.0/height);
	

	
	PV2D center_tmp = PV2D(*center);
	center->x = 0; center->y = 0;
	ret = Circle::collisionDetection(&p_tmp,&v_tmp,tIn,normalIn);
	center->x = center_tmp.x; center->y = center_tmp.y;
	if (ret) normalIn->scale(height,width);
	return ret;
}

ConvexPolygon* Elipse::createBoundingBox(double dist){
	ConvexPolygon* ret;
	ret = new Elipse(new PV2D(*center), width+dist, height+dist);
	return ret;
}