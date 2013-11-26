#include "ConvexPolygon.h"


ConvexPolygon::ConvexPolygon(void)
{

}

bool ConvexPolygon::cyrusBeck(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){

	tIn=0; double tOut=1;
	int i=0; bool find = false;
	double tHit;
	while (!find && i<nSides){
		double numerator = -(*p - *vertex[i]).dot(n[i]);
		double denominator = v->dot(n[i]);
		if(denominator == 0 && numerator >= 0) find = true;
		else if (!(denominator == 0 && numerator <0)){
			tHit = numerator/denominator;
			if (numerator<0){
				if (tHit>tIn){
					tIn = tHit;
					normalIn = n[i];
				}
			} else if (numerator > 0) tOut = min(tOut,tHit);
			find = tIn>tOut;
		}
		i++;
	}
	return !find;
}