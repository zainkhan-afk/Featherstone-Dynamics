#pragma once

#include "cinder/gl/gl.h"

class MyPlane
{
public:
	MyPlane(const ci::gl::GlslProgRef& mGlsl, const ci::vec2& _size = ci::vec2(10, 10), const ci::vec3& _planeNormal = ci::vec3(0, 0, 1));
	~MyPlane();

	void Draw();

private:
	ci::gl::BatchRef objectRef;

	ci::vec3 position;
};

