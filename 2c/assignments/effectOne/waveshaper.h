#pragma once
#include "effect.h"
#include <iostream>
#include <math.h>

class Waveshaper : public Effect {

    public:
	Waveshaper();
	~Waveshaper();

	void applyEffect(const float &input, float &output) override;

	void setShapeSlope(int slope); // TODO rethink name
	long m_slope = 999999; //TODO make into float or long
};
