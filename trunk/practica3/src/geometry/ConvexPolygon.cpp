#include "ConvexPolygon.h"


ConvexPolygon::ConvexPolygon(void)
{
	isClosed = false;
	color = new RGBColor(0,0,0);
}

ConvexPolygon::~ConvexPolygon(void)
{
	delete color; color = nullptr;
	for (PV2D* p: vertex){ delete p; p = nullptr;}
	for (PV2D* n: normal){ delete n; n = nullptr;}
}

void ConvexPolygon::addVertex(double x, double y){
	if (isClosed) return;
	PV2D* p = new PV2D(x,y);
	vertex.push_back(p);
}

void ConvexPolygon::addVertex(PV2D* p){
	if (isClosed) return;
	vertex.push_back(p);
}

void ConvexPolygon::closePolygon(){
	if (isClosed) return;
	int n = vertex.size();
	//PiP.normal
	for (int i=0;i<n;i++) normal.push_back(new PV2D((*vertex[i]-*vertex[(i+1)%n]).normal()));
	isClosed = true;
}

void ConvexPolygon::move(double x, double y){
	for (PV2D* p: vertex){
		p->x += x;
		p->y += y;
	}
}

void ConvexPolygon::render(bool debug){

	
	if (debug){
		int n = vertex.size();
		glColor3d(1,1,0);
		glBegin ( GL_LINE_STRIP) ;
			for (int i=0;i<n;i++) glVertex2d(vertex[i]->x,vertex[i]->y);
			glVertex2d(vertex[0]->x,vertex[0]->y);
		glEnd();
		/*
		int sN = SCALE_NORMAL_FACTOR;
		glColor3d(1,0,0);
		glBegin (GL_LINES ) ;
			
			for (int i=0;i<n;i++){
				int j = (i+1)%n;
				glVertex2d((vertex[i]->x+vertex[j]->x)/2,(vertex[i]->y+vertex[j]->y)/2);
				glVertex2d((vertex[i]->x+vertex[j]->x)/2+sN*normal[i]->x,(vertex[i]->y+vertex[j]->y)/2+sN*normal[i]->y);
			}
		glEnd();
		*/
	} else {
		glColor3d(color->r,color->g,color->b);
		glBegin ( GL_POLYGON ) ;
			for (PV2D* p: vertex)	glVertex2d(p->x, p->y);
			glVertex2d(vertex[0]->x,vertex[0]->y);
		glEnd () ;
	}
}

bool ConvexPolygon::collisionDetection(PV2D* p, PV2D* v, double& tIn, PV2D*& normalIn){

	tIn=0; double tOut=1;
	int i=0; bool find = false;
	double tHit;
	int nSides = vertex.size();
	while (!find && i<nSides){
		double numerator = -(*p - *vertex[i]).dot(normal[i]);
		double denominator = v->dot(normal[i]);
		if(denominator == 0 && numerator >= 0) find = true;
		else if (!(denominator == 0 && numerator <0)){
			tHit = numerator/denominator;
			if (denominator < 0){
				if (tHit>tIn){
					tIn = tHit;
					normalIn = normal[i];
				}
			} else if (denominator > 0) tOut = min(tOut,tHit);
			find = tIn>tOut;
		}
		i++;
	}
	return !find;
}

ConvexPolygon* ConvexPolygon::createBoundingBox(double dist){
	ConvexPolygon* ret = new ConvexPolygon();
	vector<PV2D*> tmp;
	int j;
	int n = vertex.size();
	PV2D p1,p2;
	for (int i=0;i<n;i++){
		j = (i+n-1)%n;
		p1 = *normal[j]; p1.scale(dist); p1 = *vertex[i]+p1;
		p2 = *normal[i]; p2.scale(dist); p2 = *vertex[i]+p2;
		tmp = createArc(vertex[i],&p1,&p2);
		for (PV2D* p : tmp) ret->addVertex(p);
		tmp.clear();
	}
	ret->closePolygon();
	return ret;
}
	
vector<PV2D*> ConvexPolygon::createArc(PV2D* center, PV2D* p1, PV2D* p2){


	vector<PV2D*> ret;
	
	Turtle *turtle = new Turtle(center);
	int num = 30;

	double dist_p1_p2 = (*p1-*p2).mod();
	double radius = (*p1 - *center).mod();

	double alpha = asin(dist_p1_p2/(2*radius));
	alpha *= 2;
	int num_p = (alpha/(2*PI))*num + 1;
	double alpha_p = alpha/num_p;
	double beta_p = (PI-alpha_p)/2.0;
	double side = 2.0*radius*alpha_p/2.0;

	turtle->lookAt(p1);
	turtle->forward(radius);
	ret.push_back(new PV2D(turtle->getPosition()));
	
	turtle->turnTo(PI-beta_p);
	for (int i=1;i<num_p;i++){
		turtle->forward(side);
		ret.push_back(new PV2D(turtle->getPosition()));
		turtle->turnTo(PI- 2*beta_p);
	}
	delete turtle;

	return ret;
}