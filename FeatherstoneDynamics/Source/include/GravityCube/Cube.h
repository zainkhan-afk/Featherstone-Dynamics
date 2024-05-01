#pragma once

#include "cinder/gl/gl.h"


class MyCube
{
public:
	MyCube(const ci::gl::GlslProgRef& mGlsl, const ci::vec3& _pos = ci::vec3(0), const ci::vec3& _vel = ci::vec3(0), float _mass = 1.0f);
	~MyCube();

	void Draw();

private:
	ci::gl::BatchRef objectRef;
	
	float ang{ 0.0f };

public:
	float mass{ 1.0f };
	ci::vec3 position;
	ci::vec3 veloctiy;
	ci::vec3 acceleration;
};

