#pragma once

#include <iostream>
#define BUFFERSIZE 512;

class CircBuffer {
    public:
	CircBuffer(int size, int numSamplesDelay);
	~CircBuffer();
	// TODO - add write and reads
	float* buffer;

    private:
	// TODO - add fields
	int bufferSize = 512;
};
