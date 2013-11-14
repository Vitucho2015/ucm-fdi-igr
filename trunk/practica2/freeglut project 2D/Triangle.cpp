#include "Triangle.h"


Triangle::Triangle(PV2D* p1,PV2D* p2,PV2D* p3)
{
	vertex[0] = *p1;
	vertex[1] = *p2;
	vertex[2] = *p3;
	for (int i=0;i<3;i++) normal[i] = (vertex[i]-vertex[(i+1)%3]).normal();
}


Triangle::~Triangle(void)
{
}

bool Triangle::intersectionLine2Triangle (PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){

	//Compute the vectors dist, proj and sign
	int sign[3]; 
	double proj[3];
	double dist[3];


	int sum= sign[0] + sign[1] + sign[2];
	if (abs(sum)==3) return false;

	int nHits=0; double hit[3]; PV2D* n[3];
	for (int i=0; i<3; i++) {
		int j = (i+1)%3;
		if (sign[i]*sign[j]<0){
			//Compute numerator
			double numerator;
			//Compute denominator
			double denominator;
			hit[nHits] = numerator/denominator;
			//n[nHits] = vector normal
			nHits++;
		}
	}

	if (nHits<2) {
		for (int i=0;i<3;i++){
			if (sign[i] == 0){
				hit[nHits] = proj[i];
				//n[nHits] = vector from triangle's center to Pi
				nHits++;
			}
		}
	}

	int m; // index of the minimum value inside vector hit
	tIn = hit[m];
	normalIn = n[m];
	return true;
}

void Triangle::render(){
	glColor3d(color.r,color.g,color.b);
	glBegin ( GL_TRIANGLES ) ;
		for (int i=0;i<3;i++) glVertex2d(vertex[i].x,vertex[i].y);
	glEnd () ;
}