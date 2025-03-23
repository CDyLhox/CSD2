#include "delay.h"
#include <iostream>




Delay::Delay(int size, int numSamplesDelay, float feedback, float drywet){
	// Dynamic array
	std::cout << "numSamplesDelay: " << numSamplesDelay << std::endl;
	bufferSize = size;
	writeHeadPosition = numSamplesDelay;
	allocateBuffer(size);
}
Delay::~Delay(){
	std::cout << "i have been a delay" << std::endl;
	releaseBuffer();
}


void CircBuffer::allocateBuffer(int size)
{ // check out malloc after this.

	buffer = new float[size];
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
}

void CircBuffer::releaseBuffer()
{
	delete[] buffer;
	buffer = nullptr;
	std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
		  << buffer << std::endl;
}


void Delay::applyEffect(const float &input, float &output){
	
	}


void Delay::setDelayTime(int numSamplesDelay)
{ 	// take current writeheadPosition and last numSamplesDelay setting.
	// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition

	readHeadPosition = writeHeadPosition - numSamplesDelay + bufferSize;
	wrapHeads(readHeadPosition);
}
void Delay::setDelayTime(float miliSecondsDelay) {
	//SAMPLERATE / (miliSecondsDelay/1000) 
	float samplesPerMilisecond = SAMPLERATE / (miliSecondsDelay/1000);	
	readHeadPosition = writeHeadPosition - samplesPerMilisecond + bufferSize;
	wrapHeads(readHeadPosition);
}
