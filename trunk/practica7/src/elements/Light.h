#pragma once
#include "PV3D.h"
class Light {

protected:
	PV3D* pos;
	bool local_light;
	GLenum id;

public:
	Light(GLenum id);
	~Light(void);

	void setPos(PV3D* pos){this->pos = pos; update();};
	void setLocal_light(bool local_light){this->local_light = local_light; update();};

	void setDiffuse(GLfloat v[]){glLightfv(id, GL_DIFFUSE, v);};
	void setAmbient(GLfloat v[]){glLightfv(id, GL_AMBIENT, v);};
	void setSpecular(GLfloat v[]){glLightfv(id, GL_SPECULAR, v);};
	
	void resetDiffuse(){GLfloat v[] = {1,1,1,1}; setDiffuse(v);};
	void resetAmbient(){GLfloat v[] = {0,0,0,1}; setAmbient(v);};
	void resetSpecular(){GLfloat v[] = {1,1,1,1}; setSpecular(v);};

	void on(){glEnable(id);};
	void off(){glDisable(id);};



private:
	void update();

};

