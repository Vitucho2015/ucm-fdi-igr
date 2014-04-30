#include "BilliardScene.h"


BilliardScene::BilliardScene(void) : Scene(){
	
	
	BilliardTable* billiard = new BilliardTable();
	addObject(billiard);
	
	Ball* ball = new Ball(0.05);
	ball->color.setColor(0.9,0.9,0.9);
	ball->mT.translate(1,0.1,3);
	addObject(ball);

	Balls* balls = new Balls();
	balls->mT.translate(0.35,0.05,0.35);
	addObject(balls);
	
	Chalk* chalk = new Chalk(0.1);
	chalk->mT.rotate(-45,0,0);
	chalk->mT.translate(0,0.1,0.05);
	
	addObject(chalk);

	mT.translate(0,2,0);

}


BilliardScene::~BilliardScene(void)
{
}
