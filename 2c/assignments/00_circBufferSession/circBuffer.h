#pragma once

#include <iostream>

class CircBuffer {
    public:
	CircBuffer();
	CircBuffer(int bufferSize, int numSamplesDelay);
	~CircBuffer();
	// TODO - add write and reads
	float* buffer;
	float readHead(int currentSample);
	void writeHead(int currentSample);
	void tickBufferHeads(uint readHeadPosition, uint writeHeadPosition);
	void allocateBuffer(int size);
	void releaseBuffer();

    private:
	// TODO - add fields
	uint bufferSize = 512;
	uint currentSample = 0;

	uint rWDistance = 0;
	uint readHeadPosition = 0;
	uint writeHeadPosition = 0;

	inline void tick()
	{
		incrementWriteHead();
		incrementReadHead();
	}

	inline void incrementWriteHead()
	{
		readHeadPosition++;
		wrapHeads(readHeadPosition);
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
