#pragma once

#include <iostream>

class CircBuffer {
    public:
	CircBuffer();
	CircBuffer(int bufferSize, int numSamplesDelay);
	~CircBuffer();
	float* buffer;
	float readHead();
	void writeHead(int currentSample);
	void allocateBuffer(int size);
	void releaseBuffer();
	
	void setDelayTime(int numSamplesDelay); 
	void setDelayTime(float miliSecondsDelay);

	inline void tick()
	{
		std::cout << "tick" << std::endl;
		incrementWriteHead();
		incrementReadHead();

		std::cout << "readHeadPosition" << readHeadPosition << std::endl;
		std::cout << "writeHeadPosition" << writeHeadPosition << std::endl;
	}

    private:
	uint bufferSize = 200;
	uint currentSample = 0;
	int numSamplesDelay;
	float miliSecondsDelay;

	uint rWDistance = 0;
	uint readHeadPosition = 0;
	uint writeHeadPosition = 10;

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
