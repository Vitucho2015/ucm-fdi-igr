/**
	Autor: Xavier Gallofré Nieva
*/
#pragma once
#include "scene.h"
#include "elements\BilliardTable.h"
#include "elements\Balls.h"
#include "elements\Chalk.h"
#include "elements\Spotlight.h"

class BilliardScene : public Scene {

public:
	Spotlight* spotlight;
	BilliardScene(void);
	~BilliardScene(void){};

	void setup_fog();
	void setup_lights();
};

