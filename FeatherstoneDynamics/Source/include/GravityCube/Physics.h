#pragma once

#include "cinder/gl/gl.h"
#include "GravityCube/Cube.h"

class Physics
{
public:
	Physics();
	~Physics();

	void SetForce(ci::vec3 F);

	void Step(MyCube* c, float dt);

private:
	ci::vec3 G = ci::vec3(0, 0, -1);
	ci::vec3 cubeF = ci::vec3(0, 0, 0);
};

