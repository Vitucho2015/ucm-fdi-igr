#include "Ball.h"

Ball::Ball(PV2D* center, double radius)
{
	circle = new Circle(center, radius);
	this->center = center;
	this->radius = radius;
	rotation = 0;
	clockwise = true;
}


Ball::~Ball(void)
{
	delete circle;
}


void Ball::step(double t){
	tail.push(new PV2D(*center));
	center->x = center->x + t*vel.x;
	center->y = center->y + t*vel.y;
	if (tail.size() > 50) tail.pop();
	if (clockwise){
		rotation += INCR_THETA;
		if ( rotation > 360.0) rotation -= 360.0;
	} else {
		rotation -= INCR_THETA;
		if ( rotation < 0 ) rotation += 360.0;
	}
	circle->setRotation(rotation);
}

void Ball::bounce(PV2D* normal){
	//Change vel (reflection)
	PV2D *an, *bn;
	vel.split(normal, an, bn);
	an->scale(2);
	vel = vel - *an;
	v1 = vel; v1.nor();
	clockwise = !clockwise;
}

void Ball::render(bool debug){
	circle->render(false);
	if (debug){
		glColor3f(1,0,0);
		glBegin(GL_LINES);
			glVertex2d(center->x,center->y);
			glVertex2d(center->x+vel.x,center->y+vel.y);
		glEnd();
		queue<PV2D*> tmp = tail;
		PV2D* p;
		glBegin( GL_POINTS );
			while (!tmp.empty()){
				p = tmp.front();
				tmp.pop();
				glVertex2d(p->x, p->y);
			}
		glEnd();
	}
}
