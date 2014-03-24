#pragma once

#include "mesh.h"
#include "RegularPolygon.h"
#include "CurveP5.h"
#include "CurveCirc.h"

class RollerCoaster : public Mesh {
public:
	RollerCoaster(int np, int nq);
	~RollerCoaster(void);
};

