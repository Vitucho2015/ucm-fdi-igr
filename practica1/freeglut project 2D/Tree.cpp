#include "Tree.h"


Tree::Tree(void)
{
	initColors();
	lastLevel = 0;
}

Tree::Tree(Square *square)
{
	initColors();
	square->setColor(colors[0]);
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
	turtle.turnTo(alpha);
	double side = square->getSide();
	turtle.forward(side/sqrt(2));
	return turtle.getPosition();
}

void Tree::generateChildsFor(int i){
	Square sq_base = squares[i];
	PV2D sup = getSupportPoint(&sq_base, PI/4+PI/36);
	Square sq_1(&sq_base.getVertex(3), &sup);
	squares.push_back(sq_1);
	Square sq_2(&sup, &sq_base.getVertex(2));
	squares.push_back(sq_2);
}

void Tree::generateNewLevel(){
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
	/*
	Browns
	82	49	39
	97	54	34	
	112	59	29
	127	64	24
	139	69	19
	*/
	colors.push_back(Color(82,49,39));
	colors.push_back(Color(97,54,34));
	colors.push_back(Color(112,59,29));
	colors.push_back(Color(127,64,24));
	colors.push_back(Color(139,69,19));
	/*
	Greens
	10	140	6
	14	147	10
	18	154	14
	22	161	18
	26	168	22
	30	175	26
	34	182	30
	38	189	34
	42	196	38
	46	203	42
	*/
	colors.push_back(Color(10,140,6));
	colors.push_back(Color(14,147,10));
	colors.push_back(Color(18,154,14));
	colors.push_back(Color(22,161,18));
	colors.push_back(Color(26,168,22));
	colors.push_back(Color(30,175,26));
	colors.push_back(Color(34,182,30));
	colors.push_back(Color(38,189,34));
	colors.push_back(Color(42,196,38));
	colors.push_back(Color(46,203,42));
}

void Tree::render(){
	for (unsigned int i=0;i<squares.size();i++){
		squares[i].render();
	}
}