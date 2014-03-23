#include "Polygon.h"

Polygon::Polygon(void){
	isClosed = false;
}

Polygon::~Polygon(void){

}

void Polygon::addVertex(PV3D* v){
	if (isClosed) return;
	vertex.push_back(v);
}

void Polygon::close(){
	isClosed = true;
	face.push_back(new Face(vertex.size()));
	PV3D* n = getNormalVector_Newell(0);
	normal.push_back(n);
}

Mesh* Polygon::extrude(PV3D* dir){
	Mesh* mesh = this->clone();
	mesh->translate(dir);

	return extrude((Polygon*) mesh);
}

Mesh* Polygon::extrude(Polygon* p){
	Mesh* mesh = new Mesh();
	
	int N = vertex.size();
	vector<PV3D*> vertex1 = getVertex();
	vector<PV3D*> vertex2 = p->getVertex();
	vector<PV3D*> vertex_;

	for (PV3D* v : vertex1) vertex_.push_back(v->clone());
	for (PV3D* v : vertex2) vertex_.push_back(v->clone());
	
	vector<Face*> face_;
	Face* f;
	for (int j=0;j<N;j++){
		f = new Face(4);
		f->setVertex(0,j);
		f->setVertex(1,(j+1)%N);
		f->setVertex(2,(j+1)%N+N);
		f->setVertex(3,j+N);
		f->setNormal(j);
		face_.push_back(f);
	}

	mesh->setVertex(vertex_);
	mesh->setFace(face_);

	vector<PV3D*> normal_;
	for (int j=0;j<N;j++) normal_.push_back(mesh->getNormalVector_Newell(j)); 

	mesh->setNormal(normal_);
	return mesh;
}