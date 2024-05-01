#include "GravityCube/Plane.h"


MyPlane::MyPlane(const ci::gl::GlslProgRef& mGlsl, const ci::vec2& _size, const ci::vec3& _planeNormal)
{
	objectRef = ci::gl::Batch::create(ci::geom::Plane().size(_size).normal(_planeNormal), mGlsl);
}

MyPlane::~MyPlane()
{

}

void MyPlane::Draw()
{
	ci::gl::pushModelMatrix();
	ci::gl::translate(position);
	ci::gl::color(ci::ColorA(1.0f, 1.0f, 1.0f, 1.0f));
	objectRef->draw();
	ci::gl::popModelMatrix();
}