/**
	Fichero: Tree.cpp
	Autor: Xavier Gallofré Nieva

	Clase que define el árbol. Se trata de una representación de árbol binario en un vector,
	que permite recorrer todos los cuadrados linealmente y acceder a los distintos niveles
	del árbol accediendo a las posiciones potencias de dos.
*/

#include "Tree.h"


Tree::Tree(void)
{
	initColors();
	lastLevel = 0;
	squareGlowing = -1;
}

Tree::~Tree(void)
{
}

void Tree::initTree(Square *square){
	squares.clear();
	square->setColor(colors[0]);
	squares.push_back(*square);
	lastLevel = 1;
}

bool Tree::isEmpty(){
	if (lastLevel == 0) return true; else return false;
}

PV2D Tree::getSupportPoint(Square *square, double alpha){
	
	PV2D v2 = square->getVertex(2);
	PV2D v1 = square->getVertex(1);
	Turtle turtle;
	turtle.moveTo(&v1,false);
	turtle.lookAt(&v2);
	turtle.moveTo(&v2,false);
	turtle.turnTo(alpha);
	double side = square->getSide();
	turtle.forward(side/sqrt(2));
	return turtle.getPosition();
}

void Tree::generateChildsFor(int i){
	Square sq_base = squares[i];
	float alpha = (50 + rand()%80)*PI/360; // 50/360 <= alpha < 130/360 ----
	PV2D sup = getSupportPoint(&sq_base, alpha);
	Square sq_1(&sq_base.getVertex(3), &sup);
	squares.push_back(sq_1);
	Square sq_2(&sup, &sq_base.getVertex(2));
	squares.push_back(sq_2);
}

void Tree::generateNewLevel(){
	if (lastLevel <= 0) return;
	if (lastLevel >= 14) return;
	int first = (int) pow(2,lastLevel-1);
	int last = (int) pow(2,lastLevel);
	for (int i=first;i<last;i++){
		generateChildsFor(i-1);
	}
	lastLevel++;
	if (lastLevel > colors.size()) return;
	first = last;
	last = (int) pow(2,lastLevel);
	for (int i=first;i<last;i++){
		squares[i-1].setColor(colors[lastLevel-1]);
	}
}

void Tree::deleteLastLevel(){
	if (lastLevel <= 0) return;
	int first = (int) pow(2,lastLevel-1);
	int last = (int) pow(2,lastLevel);
	int n = last - first;
	for (int i=0;i<n;i++) squares.pop_back();
	lastLevel--;
}

void Tree::initColors(){
	if (!colors.empty()) colors.clear();
	
	double r,g,b;
	// Browns	
	r=82;g=49;b=39;
	for (int i=0;i<5;i++){
		colors.push_back(RGBColor(r,g,b));
		r += 15;
		g += 5;
		b += (-5);
	}
	// Greens
	r=19;g=102;b=16;
	for (int i=0;i<10;i++){
		colors.push_back(RGBColor(r,g,b));
		r += 4;
		g += 9;
		b += 4;
	}
}

void Tree::glow(PV2D *p){
	for (int i=0;i<squares.size();i++){
		if (squares[i].isInside(p->x, p->y)){
			if (squareGlowing != -1){
				squares[squareGlowing].setColor(oldColor);
			}
			oldColor = squares[i].getColor();
			squareGlowing = i;
			squares[i].setColor(RGBColor(243,255,13));			
		}
	}
}

void Tree::render(){
	if (lastLevel <= 0) return;
	for (unsigned int i=0;i<squares.size();i++){
		squares[i].render();
	}
	PV2D aux;
	int level = 1;
	int lastSqInLvl = 0;
	int n = squares.size()/2;
	for (unsigned int i=0;i<n;i++){
		glBegin(GL_TRIANGLES);
			
			glColor3d(colors[level-1].r,colors[level-1].g,colors[level-1].b);

			aux = squares[i*2+1].getVertex(1);
			glVertex2d(aux.x, aux.y);
			aux = squares[i*2+1].getVertex(0);
			glVertex2d(aux.x, aux.y);
			aux = squares[i*2+2].getVertex(1);
			glVertex2d(aux.x, aux.y);
		glEnd();
		if (i == lastSqInLvl && level < colors.size()){
			level++;
			lastSqInLvl = lastSqInLvl*2 +2;
		}
	}
}
