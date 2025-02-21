#include "tremolo.h"

Tremolo::Tremolo(float rate, float depth)
{//TODO: add validation
 if(rate > 15000 || rate < 0){
	 std::cout << "please choose a value between 0 and 15000" << std::endl;
 }
	std::cout << "Tremolo::Tremolo. a classic example of a tremolo doing things" << std::endl;
	
}

Tremolo::~Tremolo()
{
}

void Tremolo::prepare(float sampleRate)
{
	sine.prepare(sampleRate);
}

float Tremolo::processFrame(float incomingSignal)
{
	float modSignal = sine.genNextSample() * -0.5 + 0.5;


	modSignal *= depth;
	modSignal += 1.0 - depth;

	std::cout << incomingSignal * modSignal << std::endl;
	return incomingSignal * modSignal;
}
void Tremolo::setModFreq(float freq)
{
	if (freq >= 15000) {
		std::cout << "i dont like the high slides because they scare me\n";
	}
	sine.setFrequency(freq);
}
