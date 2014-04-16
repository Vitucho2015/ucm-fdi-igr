#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "PV3D.h"

class Camera{

private:
	PV3D *eye, *look, *up;
	PV3D *u, *v, *n;
	GLdouble vv_left, vv_right, vv_top, vv_bottom;
	GLdouble vv_near, vv_far, vv_fovy, vv_aspect;

public:
	Camera(PV3D* eye, PV3D* look, PV3D* up);
	~Camera(void);

	void setView(PV3D* eye, PV3D* look, PV3D* up);
	void setCoordSystem();

	void roll(GLdouble rad);
	void yaw(GLdouble rad);
	void pitch(GLdouble rad);

	void rotateX(GLdouble alpha);
	void rotateY(GLdouble alpha);
	void rotateZ(GLdouble alpha);

	void setPosition(PV3D* p){ delete eye; eye = p; setCoordSystem(); view();};
	void translate(PV3D* p){ eye->plus(p); setCoordSystem(); view();};

	void setProjection(int mode);

	
	void view();

	void projection_ortho();
	void projection_perspective();
	void projection_oblique(PV3D* d);

	void setModelViewMatrix();
};

