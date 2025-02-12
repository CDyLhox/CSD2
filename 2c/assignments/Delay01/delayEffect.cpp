#pragma once
#include "effect.h"
#include <iostream>

class Delay : public Effect
{
	Delay(int size, int numSamplesDelay);
	~Delay();

	float* buffer;
	float readHead();
	void writeHead(int currentSample);
	void allocateBuffer(int size);
	void releaseBuffer();


	void prepare(int SAMPLERATE);
	void applyEffect(const float &input, float &output) override;
	float processFrame(const float &inut, float &output);
	float getSample();
	void setDryWet(float drywet);

	uint bufferSize = 200;
	uint currentSample = 0;
	float feedback = 0.7;

	uint rWDistance = 0;
	uint readHeadPosition = 0;
	uint writeHeadPosition = 10;

	inline void tick(){
		std::cout <<"tick" << std::endl;
		incrementWriteHead();
		incrementReadHead();

	}


	inline void incrementWriteHead()
	{
		writeHeadPosition++;
		wrapHeads(writeHeadPosition);
	}
	inline void incrementReadHead()
	{
		readHeadPosition++;
		wrapHeads(writeHeadPosition);
	}
	inline void wrapHeads(uint head)
	{
		if (head >= bufferSize) {
			head -= bufferSize;
		}
	}
	

	
};
