#include "delay.h"




Delay::Delay(int size, int numSamplesDelay){


	// Dynamic array
	std::cout << "numSamplesDelay: " << numSamplesDelay << std::endl;
	bufferSize = size;
	writeHeadPosition = numSamplesDelay;
	allocateBuffer(size);
}





void Delay::applyEffect(const float &input, float &output){
	
	}


void Delay::setDelayTime(int numSamplesDelay)
{ 	// take current writeheadPosition and last numSamplesDelay setting.
	// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
	// im wondering if this is a non nice way of organising it but i feel having the cirbuffer seperate makes sense for now
	delayBuffer.setDelayTime(int numSamplesDelay);
	writeHeadPosition++;
}
void Delay::setDelayTime(float miliSecondsDelay) {
	//SAMPLERATE / (miliSecondsDelay/1000) 
	delayBuffer.setDelayTime(float miliSecondsDelay);
}
