#pragma once

#include "Light.h"

class SetOfLights
{
private:
	Light* lights[8];

public:
	SetOfLights(void);
	~SetOfLights(void);
};

