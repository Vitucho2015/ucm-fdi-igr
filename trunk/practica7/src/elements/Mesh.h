/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once

#include <vector>
#include <Windows.h>
#include <gl/GL.h>

#include "Object3D.h"

#include "PV3D.h"
#include "Face.h"


using namespace std;

class Mesh : public Object3D{
protected:
	vector<PV3D*> vertex, normal;
	vector<Face*> face;

	bool render_filled,render_normals;

public:
	Mesh(void);
	~Mesh(void);
	Mesh* clone();

	void render();
	PV3D* getNormalVector_Newell(int face_i);

	void extrude(int face, PV3D* dist);

	void addPolygon(Mesh* p);
	void addMesh(Mesh* p);

	void translate(PV3D* dir);

	vector<PV3D*> getVertex()	{return vertex;};
	vector<PV3D*> getNormal()	{return normal;};
	vector<Face*> getFace()		{return face;};
	bool isRenderingFilled() { return render_filled;};
	bool isRenderingNormals() {return render_normals;};

	void setVertex(vector<PV3D*> vs)	{vertex = vector<PV3D*>(); for (PV3D* v : vs) vertex.push_back(v->clone());};
	void setNormal(vector<PV3D*> ns)	{normal = vector<PV3D*>(); for (PV3D* n : ns) normal.push_back(n->clone());};
	void setFace(vector<Face*> fs)		{face	= vector<Face*>(); for (Face* f : fs) face.push_back(f->clone());};
	void setRender_Filled(bool b)		{render_filled = b;};
	void setRender_Normals(bool b)		{render_normals = b;};

	void setRecoatMode(int i);
};

