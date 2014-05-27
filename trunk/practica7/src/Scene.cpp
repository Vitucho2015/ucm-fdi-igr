/**
	Autor: Xavier Gallofré Nieva
*/
#include "Scene.h"


Scene::Scene(void){}
Scene::~Scene(void){}

void Scene::setRecoatMode(int i){
	for (Object3D* o : childs) o->setRecoatMode(i);
}

void Scene::render(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixd(mT.m);
		for (Object3D* o : childs) o->render();
		setup_lights();
	glPopMatrix();
}