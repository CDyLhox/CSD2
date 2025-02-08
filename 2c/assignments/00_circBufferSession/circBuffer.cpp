#include "circBuffer.h"

CircBuffer::CircBuffer()
    : CircBuffer(200, 500)
{
} // set default constructor
CircBuffer::CircBuffer(int size, int numSamplesDelay)
{
	// TODO - init buffer
	// Dynamic array
	
	allocateBuffer(size);


	std::cout << "Elements of the array are: ";
	for (int i = 0; i < size; i++) {
		std::cout << buffer[i] << " ";
	}
	std::cout << buffer << std::endl;
}

CircBuffer::~CircBuffer()
{
	// TODO - release the dynamic allocated array
	releaseBuffer();
}

void CircBuffer::allocateBuffer(int size)
{//check out malloc after this.

	buffer = new float[bufferSize];
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
}

void CircBuffer::releaseBuffer(){
	delete[] buffer;
	std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
	       << buffer << std::endl;
}

float CircBuffer::readHead()
{
	return buffer[currentSample];
}

void CircBuffer::writeHead(int currentSample)
{
	buffer[currentSample] = currentSample; // input
}

