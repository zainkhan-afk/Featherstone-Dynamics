#include "GravityCube/Physics.h"

Physics::Physics() {}
Physics::~Physics() {}

void Physics::SetForce(ci::vec3 F)
{
	cubeF = F;
}

void Physics::Step(MyCube* c, float dt)
{
	c->acceleration = G + cubeF / c->mass;
	c->veloctiy += c->acceleration * dt;
	c->position += c->veloctiy * dt;

	cubeF = ci::vec3(0, 0, 0);
}
