#pragma once

#include <iostream>

class CircBuffer {
    public:
	CircBuffer();
	CircBuffer(int bufferSize, int numSamplesDelay);
	~CircBuffer();
	// TODO - add write and reads
	float* buffer;
	float readHead();
	void writeHead(int currentSample);
	void allocateBuffer(int size);
	void releaseBuffer();

	inline void tick()
	{
		std::cout << "tick" << std::endl;
		incrementWriteHead();
		incrementReadHead();

//std::cout << "Elements of the array are: ";
//		for (int i = 0; i < 512; i++) {
//			std::cout << buffer[i] << " ";
//		}
	}

    private:
	// TODO - add fields
	uint bufferSize = 512;
	uint currentSample = 0;
	int numSamplesDelay;

	uint rWDistance = 0;
	uint readHeadPosition = 0;
	uint writeHeadPosition = 10;

	inline void incrementWriteHead()
	{
		readHeadPosition++;
		wrapHeads(readHeadPosition);
		std::cout << "readHeadPosition" << readHeadPosition << std::endl;
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
