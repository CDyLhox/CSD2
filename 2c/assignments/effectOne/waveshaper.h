#pragma once
#include "effect.h"
#include <iostream>
#include <math.h>

class Waveshaper : public Effect {

    public:
	Waveshaper();
	~Waveshaper();

	void applyEffect(const float& input, float& output) override;
	void setSlope(long slope); 
    private:

	long  m_slope = 1;

};
