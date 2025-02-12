
#pragma once
#include "effect.h"
#include "circBuffer.h"
#include <iostream>

class Delay : public Effect
{
	public:
	Delay(int size, int numSamplesDelay);
	~Delay();

	float readHead();
	void writeHead(int currentSample);
	void allocateBuffer(int size);
	void releaseBuffer();

	void applyEffect(const float &input, float &output) override;


	void setDelayTime(int numSamplesDelay); 
	void setDelayTime(float miliSecondsDelay);
	void setFeedBack(float feedback);
	private:
	float* buffer;


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
