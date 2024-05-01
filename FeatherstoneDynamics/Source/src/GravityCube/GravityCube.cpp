#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
//#include "cinder/ImageIo.h"
#include "cinder/Log.h"


#include "GraphicsDemo/Resources.h"
#include "GravityCube/Cube.h"
#include "GravityCube/Plane.h"
#include "GravityCube/Physics.h"

using namespace ci;
using namespace ci::app;

class RotatingCubeApp : public App {
public:
	void	setup() override;
	void	resize() override;
	void	update() override;

	void	draw() override;

	void keyDown(KeyEvent event);

	CameraPersp			mCam;
	gl::GlslProgRef		mGlsl;
	mat4				mCubeRotation;
	MyCube*				myCube;
	MyPlane*			myPlane;
	Physics				phy;

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

	myCube = new MyCube(mGlsl, vec3(0, 0, 2));
	myPlane = new MyPlane(mGlsl);

	gl::enableDepthWrite();
	gl::enableDepthRead();
}

void RotatingCubeApp::resize()
{
	mCam.setPerspective(60, getWindowAspectRatio(), 1, 1000);
	mCam.lookAt(vec3(7, 7, 3), vec3(0), vec3(0, 0, 1));
	gl::setMatrices(mCam);
}

void RotatingCubeApp::update()
{
	phy.Step(myCube, 0.05f);
}

void RotatingCubeApp::draw()
{
	gl::clear();
	gl::setMatrices(mCam);

	myCube->Draw();
	myPlane->Draw();
}

void RotatingCubeApp::keyDown(KeyEvent event)
{
	switch (event.getCode()) {
	case KeyEvent::KEY_SPACE:
		phy.SetForce(vec3(0, 0, 50));
		break;
	}
}

CINDER_APP(RotatingCubeApp, RendererGl(RendererGl::Options().msaa(16)))
