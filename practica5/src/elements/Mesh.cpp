#include "Mesh.h"


Mesh::Mesh(void){
	render_filled = false;
	render_normals = false;
}


Mesh::~Mesh(void)
{
}

void Mesh::render(){
	//Faces
	glColor3f(0,0,1);
	for (int i=0; i<face.size();i++){
		glLineWidth(1.0);
		render_filled ? glBegin(GL_POLYGON) : glBegin(GL_LINE_LOOP);
		for (int j=0; j<face[i]->getNumVertex(); j++) {
			int iN = face[i]->getVertexNormal(j).normalIndex;
			int iV = face[i]->getVertexNormal(j).vertexIndex;
			glNormal3f(normal[iN]->x, normal[iN]->y, normal[iN]->z);
			//Texture Coords Here (j index) with glTexCoor2f
			glVertex3f(vertex[iV]->x, vertex[iV]->y, vertex[iV]->z);
		}
		glEnd();
	}
	
	//Normals
	if (render_normals){
	PV3D *tmp, *center, *n;
	glColor3f(1,0,0);
	for (int i=0; i<face.size();i++){
		center = new PV3D();
		for (int j=0; j<face[i]->getNumVertex(); j++) {
			int iV = face[i]->getVertexNormal(j).vertexIndex;
			tmp = vertex[iV]->clone();
			tmp->scale(1.0/face[i]->getNumVertex());
			center->plus(tmp);
		}
		glBegin(GL_LINES);
			glVertex3f(center->x, center->y, center->z);
			n = normal[face[i]->getVertexNormal(0).normalIndex];
			glVertex3f(center->x + n->x, center->y + n->y, center->z + n->z);
		glEnd();
	}
	glColor3f(0,0,1);
	}
	
}


PV3D* Mesh::getNormalVector_Newell(int face_i){
	PV3D* n = new PV3D();
	PV3D *currVertex, *nextVertex;
	Face* f = face[face_i];
	for (int i=0;i<f->getNumVertex();i++){
		currVertex = vertex[f->getVertexNormal(i).vertexIndex];
		nextVertex = vertex[f->getVertexNormal((i+1)%f->getNumVertex()).vertexIndex];
		n->x += (currVertex->y - nextVertex->y) * (currVertex->z + nextVertex->z);
		n->y += (currVertex->z - nextVertex->z) * (currVertex->x + nextVertex->x);
		n->z += (currVertex->x - nextVertex->x) * (currVertex->y + nextVertex->y);
	}
	n->normalize();
	n->scale(-1);
	return n;
}

void Mesh::addPolygon(Mesh* p){
	
	vector<PV3D*> vertex_ = p->getVertex();
	vector<PV3D*> normal_ = p->getNormal();
	vector<Face*> face_		= p->getFace();
	
	for (PV3D* v : vertex_) vertex.push_back(v->clone());
	for (PV3D* n : normal_) normal.push_back(n->clone());
	
}

void Mesh::addMesh(Mesh* p){
	
	vector<PV3D*> vertex_ = p->getVertex();
	vector<PV3D*> normal_ = p->getNormal();
	vector<Face*> face_		= p->getFace();
	
	int n_normal, n_vertex;
	n_vertex = vertex.size();
	n_normal = normal.size();

	for (PV3D* v : vertex_) vertex.push_back(v->clone());	
	for (PV3D* n : normal_) normal.push_back(n->clone());
	
	Pair_VertexNormal vn;
	for (Face* f : face_){
		for (int i=0;i<f->getNumVertex();i++){
			vn = f->getVertexNormal(i);
			f->setVertex(i,n_vertex + vn.vertexIndex);
			f->setNormal(i,n_normal + vn.normalIndex);
		}
		face.push_back(f->clone());
	}

}

void Mesh::translate(PV3D* dir){
	for (PV3D* p : vertex) p->plus(dir);
}

Mesh* Mesh::clone(){
	Mesh* ret = new Mesh();
	
	ret->setVertex(vertex);
	ret->setNormal(normal);
	ret->setFace(face);
	
	return ret;
}