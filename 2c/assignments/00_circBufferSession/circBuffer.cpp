#include "circBuffer.h"

CircBuffer::CircBuffer(int size, int numSamplesDelay)
{
	// TODO - init buffer
	// Dynamic array
	buffer = new float[bufferSize];
	for (int i = 0; i < size; i++) {
		buffer[i] = i + 1;
	}

	std::cout << "Elements of the array are: ";
	for (int i = 0; i < size; i++) {
		std::cout << buffer[i] << " ";
	}
	std::cout << buffer << std::endl;
}

CircBuffer::~CircBuffer()
{
	delete[] buffer;
	// TODO - release the dynamic allocated array
}
