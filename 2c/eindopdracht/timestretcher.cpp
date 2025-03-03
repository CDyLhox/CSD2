#include "timestretcher.h"
#include <iostream>

void Timestretcher::applyEffect(const float &input, float &output){
				
				output = input;
}

void Timestretcher::setAmountZeroCrossings(uint timeStretchLength){
	m_NumZeroCrossings = timeStretchLength;
	acircbuffer.setNumDelaySamples(uint numDelaySamples);
}
