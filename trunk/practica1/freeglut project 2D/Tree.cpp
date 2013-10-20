#include "Tree.h"


Tree::Tree(void)
{
	lastLevel = 0;
}

Tree::Tree(Square *square)
{
	squares.push_back(*square);
	lastLevel = 1;
}

Tree::~Tree(void)
{
}

PV2D Tree::getSupportPoint(Square *square, double alpha){
	
	PV2D v2 = square->getVertex(2);
	PV2D v1 = square->getVertex(1);
	Turtle turtle;
	turtle.moveTo(&v1,false);
	turtle.lookAt(&v2);
	turtle.moveTo(&v2,false);
	turtle.turnTo(alpha);//Change by alpha
	double side = square->getSide();
	turtle.forward(side/sqrt(2));
	return turtle.getPosition();
}

void Tree::generateChildsFor(int i){
	Square sq_base = squares[i];
	PV2D sup = getSupportPoint(&sq_base, PI/4);
	squares.push_back(Square(&sq_base.getVertex(3), &sup));
	squares.push_back(Square(&sup, &sq_base.getVertex(2)));
}

void Tree::generateNewLevel(){
	int first = (int) pow(2,lastLevel-1);
	int last = (int) pow(2,lastLevel);
	for (int i=first;i<last;i++) generateChildsFor(i-1);
	lastLevel++;
}

void Tree::deleteLastLevel(){

	int first = (int) pow(2,lastLevel-1);
	int last = (int) pow(2,lastLevel);
	int n = last - first;
	for (int i=0;i<n;i++) squares.pop_back();
	lastLevel--;
}

void Tree::render(){
	for (unsigned int i=0;i<squares.size();i++){
		squares[i].render();
	}
}