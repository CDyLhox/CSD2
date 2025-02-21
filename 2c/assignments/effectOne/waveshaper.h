#pragma once
#include "effect.h"
#include <iostream>
#include <math.h>
#include <interpolation.h>

class Waveshaper : public Effect {

    public:
	Waveshaper();
	~Waveshaper();

	void applyEffect(const float& input, float& output) override;
	void setSlope(double slope); 
    private:
	// pirkle 
	double  m_slope = 1; //NOTE: this is the k value of the pirkle function
	float* m_waveTableBuffer;
	float m_index; 
	


};
