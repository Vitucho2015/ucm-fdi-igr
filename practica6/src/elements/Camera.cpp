#include "Camera.h"


Camera::Camera(PV3D* eye, PV3D* look, PV3D* up){
	
	setView(eye,look,up);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);

	// Viewing frustum parameters
	vv_right = 5; vv_left = -vv_right; 
	vv_top = 5; vv_bottom = -vv_top;
	vv_near = 1; vv_far = 1000;
	vv_aspect = (vv_right - vv_left)/(vv_top - vv_bottom);


	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(vv_left, vv_right, vv_bottom, vv_top, vv_near, vv_far);
}


Camera::~Camera(void){}

void Camera::setView(PV3D* eye, PV3D* look, PV3D* up){
	this->eye = eye;
	this->look = look;
	this->up = up;

	setCoordSystem();
}

void Camera::setCoordSystem(){
	n = eye->clone();
	n->minus(look);
	n->normalize();

	u = up->cross(n);
	v = n->cross(u);
}

void Camera::roll(GLdouble alpha){
	
	u->scale(cos(alpha));
	v->scale(sin(alpha));
	u->plus(v);

	v = n->cross(u);
	setModelViewMatrix();
}

void Camera::yaw(GLdouble alpha){

	n->scale(cos(alpha));
	u->scale(sin(alpha));
	n->plus(u);

	u = v->cross(n);
	setModelViewMatrix();
}

void Camera::pitch(GLdouble alpha){

	v->scale(cos(alpha));
	n->scale(sin(alpha));
	v->plus(n);

	n = u->cross(v);
	setModelViewMatrix();

}

void Camera::rotateX(GLdouble alpha){
	GLdouble eye_x = eye->x;
	eye->minus(new PV3D(eye_x,0,0));
	
	GLdouble y_ = eye->y*cos(alpha) - eye->z*sin(alpha);
	GLdouble z_ = eye->y*sin(alpha) + eye->z*cos(alpha);

	eye = new PV3D(eye_x, y_, z_);
	setCoordSystem();
	view();
}

void Camera::rotateY(GLdouble alpha){
	GLdouble eye_y = eye->y;
	eye->minus(new PV3D(0,eye_y,0));
	
	GLdouble x_ = eye->x*cos(alpha) - eye->z*sin(alpha);
	GLdouble z_ = eye->x*sin(alpha) + eye->z*cos(alpha);

	eye = new PV3D(x_, eye_y, z_);
	setCoordSystem();
	view();
}

void Camera::rotateZ(GLdouble alpha){
	GLdouble eye_z = eye->z;
	eye->minus(new PV3D(0,0,eye_z));
	
	GLdouble x_ = eye->x*cos(alpha) - eye->y*sin(alpha);
	GLdouble y_ = eye->x*sin(alpha) + eye->y*cos(alpha);

	eye = new PV3D(x_, y_, eye_z);
	setCoordSystem();
	view();
}

void Camera::view(){
	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->x, eye->y, eye->z, look->x, look->y, look->z, up->x, up->y, up->z);
}


void Camera::projection_ortho(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(vv_left, vv_right, vv_bottom, vv_top, vv_near, vv_far);
}

void Camera::projection_perspective(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(vv_left, vv_right, vv_bottom, vv_top, vv_near, vv_far);
}

void Camera::projection_oblique(PV3D* d){
	projection_ortho();
	if (d->z != 0 && d != new PV3D(0,0,1)){ //FIXME: 
		GLdouble m[16];

		m[0] = 1; m[4] = 0;	m[8] = -d->x/d->z; m[12] = -vv_near*d->x/d->z;
		m[1] = 0; m[5] = 1;	m[9] = -d->y/d->z; m[13] = -vv_near*d->y/d->z;
		m[2] = 0; m[6] = 0;	m[10] = 1; m[14] = 0;
		m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;

		glLoadMatrixd(m);
	}
}

void Camera::setModelViewMatrix(){
	glMatrixMode(GL_MODELVIEW);
	GLdouble m[16];

	m[0] = u->x;	m[4] = u->y;	m[8] = u->z; m[12] = -eye->dot(u);
	m[1] = v->x;	m[5] = v->y;	m[9] = v->z; m[13] = -eye->dot(v);
	m[2] = n->x;	m[6] = n->y;	m[10] = n->z; m[14] = -eye->dot(n);
	m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;

	glLoadMatrixd(m);
}