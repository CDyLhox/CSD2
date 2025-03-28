#pragma once

#include <iostream>
#include "sine.h"

class Tremolo {
    public:
	Tremolo(float rate, float depth);
	~Tremolo();

	float processFrame(float incomingSignal);
	void setModFreq(float freq);


	void prepare(float sampleRate);
    private:
	float rate;
	float depth = 0.5;
	Sine sine{5};

};
