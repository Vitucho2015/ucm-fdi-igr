﻿/**
	Autor: Xavier Gallofré Nieva
*/
#include "Mesh.h"


Mesh::Mesh(void){
	render_filled = false;
	render_normals = false;
}


Mesh::~Mesh(void)
{
}

void Mesh::draw(){
	//Faces
	//glColor3f(0,0,1);
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

void Mesh::setRecoatMode(int i){
	switch (i){
	case 0: render_filled = false; break;
	case 1: render_filled = true; break;
	}
}

/*
void Mesh::makeSurface(int face_i, int nU, int nV){
	//Dimensions of surface
	GLdouble uMin, uMax, vMin, vMax;
	//Increments
	GLdouble incU = (uMax-uMin)/(nU-1);
	GLdouble incV = (vMax-vMin)/(nV-1);

	for (int i=0, u=uMin; i<nU; i++, u+=incU)
		for (int j=0, v=vMin; j<nV; j++, v+=incV) {
		int indiceVertice = i*nV+j;
		//Coordenadas del vértice y de la normal (indiceVertice)‐ésimo
		vertex[indiceVertice] = new PV3D(X(u,v), Y(u,v), Z(u,v), 1);
		normal[indiceVertice] = new PV3D(nX(u,v), nY(u,v), nZ(u,v), 0);
		normal[indiceVertice]‐>normalizar();
		//Construcción de caras cuadrangulares
		if (i>0 && j>0) {
			int indiceCara = (i‐1)*(nV‐1)+(j‐1);
			Pair_VertexNormal** vn = new Pair_VertexNormal*[4];
			face[indiceCara]->setNormal
			vn[0]=new VerticeNormal(indiceVertice,indiceVertice);
			vn[1]=new VerticeNormal(indiceVertice‐nV,indiceVertice‐nV);
			vn[2]=new VerticeNormal(indiceVertice‐nV‐1,indiceVertice‐nV‐1);
			vn[3]=new VerticeNormal(indiceVertice‐1,indiceVertice‐1);
			cara[indiceCara] = new Cara(4, vn);
		}//if
	}//for
}
*/