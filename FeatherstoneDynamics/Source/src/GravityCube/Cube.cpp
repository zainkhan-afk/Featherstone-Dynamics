#include "GravityCube/Cube.h"
#include <math.h>
MyCube::MyCube(const ci::gl::GlslProgRef& mGlsl, const ci::vec3& _pos, const ci::vec3& _vel, float _mass) : position(_pos), veloctiy(_vel), mass(_mass)
{
	objectRef = ci::gl::Batch::create(ci::geom::Cube().size(ci::vec3(1, 1, 1)), mGlsl);
}

MyCube::~MyCube()
{
}

void MyCube::Draw()
{
	ci::gl::pushModelMatrix();
	ci::gl::translate(position);
	ci::gl::color(ci::ColorA(1.0f, 0.0f, 0.0f, 1.0f));
	objectRef->draw();
	ci::gl::popModelMatrix();

	ang += 0.01f;
}
