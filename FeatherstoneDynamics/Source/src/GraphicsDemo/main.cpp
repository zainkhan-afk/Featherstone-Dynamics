#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/Log.h"
#include "GraphicsDemo/Resources.h"

using namespace ci;
using namespace ci::app;

class RotatingCubeApp : public App {
public:
	void	setup() override;
	void	resize() override;
	void	update() override;



	void	DrawCube();
	void	DrawPlane();
	void	draw() override;

	CameraPersp			mCam;
	gl::BatchRef		mCube;
	gl::BatchRef		mPlane;
	gl::GlslProgRef		mGlsl;
	mat4				mCubeRotation;

	vec3				mCubePos;
	vec3				mPlanePos;

	double				ang = 0.0;
};

void RotatingCubeApp::setup()
{
	try {
		mGlsl = gl::GlslProg::create(loadResource(RES_VERT_SHADER), loadResource(RES_FRAG_SHADER));
		CI_LOG_I("Loaded shader");
	}
	catch (const std::exception& e) {
		CI_LOG_E("Shader Error: " << e.what());
	}

	mCube = gl::Batch::create(geom::Cube().size(vec3(1, 1, 1)), mGlsl);
	mPlane = gl::Batch::create(geom::Plane().size(vec2(10, 10)).normal(vec3(0, 0, 1)), mGlsl);

	mPlanePos = vec3(0, 0, 0);
	mCubePos = vec3(0, 0, 2);

	gl::enableDepthWrite();
	gl::enableDepthRead();
}

void RotatingCubeApp::resize()
{
	mCam.setPerspective(60, getWindowAspectRatio(), 1, 1000);
	mCam.lookAt(vec3(5, 2, 3), vec3(0), vec3(0, 0, 1));
	gl::setMatrices(mCam);
}

void RotatingCubeApp::update()
{
	//mCubeRotation *= rotate(toRadians(0.2f), normalize(vec3(0, 0, 1)));
}

void RotatingCubeApp::draw()
{
	gl::clear();

	gl::setMatrices(mCam);
	
	// Draw Cube
	DrawCube();

	// Draw Plane
	DrawPlane();
	ang += 0.01;
}

void RotatingCubeApp::DrawCube()
{
	gl::pushModelMatrix();
	gl::translate(mCubePos + vec3(0, 0, sin(ang)));
	gl::color(Color(1.0f, 0.0f, 0.0f));
	mCube->draw();
	gl::popModelMatrix();
}
void RotatingCubeApp::DrawPlane()
{
	gl::pushModelMatrix();
	gl::translate(mPlanePos);
	gl::color(Color(0.0f, 0.0f, 1.0f));
	mPlane->draw();
	gl::popModelMatrix();
}

CINDER_APP(RotatingCubeApp, RendererGl(RendererGl::Options().msaa(16)))
