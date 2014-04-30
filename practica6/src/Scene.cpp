/**
	Autor: Xavier Gallofré Nieva
*/
#include "Scene.h"


Scene::Scene(void)
{
}


Scene::~Scene(void)
{
}

void Scene::addObject(Object3D* obj){
	objects.push_back(obj);
}

void Scene::draw(){
	drawAxis();
	for (Object3D* o : objects) o->render();
}

void Scene::drawAxis(){
	
	glBegin( GL_LINES );
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     
	 
		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 
	 
		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

}