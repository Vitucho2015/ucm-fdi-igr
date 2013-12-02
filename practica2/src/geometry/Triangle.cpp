#include "Triangle.h"

Triangle::Triangle(PV2D* p1,PV2D* p2,PV2D* p3)
{
	addVertex(p1);
	addVertex(p2);
	addVertex(p3);
	closePolygon();
}



bool Triangle::collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){
		//Compute the vectors dist, proj and sign
	int sign[3]; 
	double proj[3];
	double dist[3];
	for (int i=0; i<3; i++){
		dist[i] = (*vertex[i] - *p).dot(&v->normal());
		proj[i] = (*vertex[i] - *p).dot(v);
		if (dist[i] < -EPSILON) sign[i] = -1;
		else if (dist[i] > EPSILON) sign[i] = 1;
		else sign[i] = 0;
	}

	int sum= sign[0] + sign[1] + sign[2];
	if (abs(sum)==3) return false;

	int nHits=0; double hit[3]; PV2D* n[3];
	for (int i=0; i<3; i++) {
		int j = (i+1)%3;
		if (sign[i]*sign[j]<0){
			//Compute numerator
			//double numerator = proj[i]*dist[j]-dist[i]*proj[j];
			//Compute denominator
			//double denominator = dist[j]-dist[i];

			double numerator = (*vertex[i] - *p).dot(normal[i]);
			double denominator = v->dot(normal[i]);
			hit[nHits] = numerator/denominator;
			n[nHits] = normal[i];
			nHits++;
		}
	}

	if (nHits<2) {
		for (int i=0;i<3;i++){
			if (sign[i] == 0){
				hit[nHits] = proj[i];
				//n[nHits] = vector from triangle's center to Pi
				n[nHits] = normal[i];
				nHits++;
			}
		}
	}

	int m; // index of the minimum value inside vector hit
	if (min(hit[0],hit[1])==hit[0]) m=0; else m=1;
	tIn = hit[m];
	normalIn = n[m];
	return true;
}
