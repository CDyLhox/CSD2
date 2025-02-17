#pragma once
#include "effect.h"
#include <iostream>
#include <math.h>

class Waveshaper : public Effect {

    public:
	Waveshaper();
	~Waveshaper();

	void applyEffect(const float& input, float& output) override;
	void setSlope(long slope); // TODO rethink name
    private:

	long  m_slope = 1;	// TODO make into float or long
	bool m_isBypassed = 0;
};
