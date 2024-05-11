#pragma once
#include "Chain/Types.h"

class Dynamics
{
public:
	Dynamics();
	~Dynamics();

private:


public:
private:
	std::vector<MathTypes::Mat6> linkInertias;
	std::vector<MathTypes::Mat6> articulatedInertias;

};

