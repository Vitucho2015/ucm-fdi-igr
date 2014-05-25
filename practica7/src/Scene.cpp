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

/*
void Scene::draw(){
	drawAxis();	
	CompositeObject::draw();	
}
*/
/*

*/
void Scene::setRecoatMode(int i){
	for (Object3D* o : childs) o->setRecoatMode(i);
}