#include "circBuffer.h"

CircBuffer::CircBuffer()
    : CircBuffer(200, 500)
{
} // set default constructor
CircBuffer::CircBuffer(int size, int numSamplesDelay)
    : bufferSize(512)
    , numSamplesDelay(10)
{
	// TODO - init buffer
	// Dynamic array
	allocateBuffer(size);

}

CircBuffer::~CircBuffer()
{
	// TODO - release the dynamic allocated array
	
	
	std::cout << "Elements of the array are: ";
	for (int i = 0; i < 512; i++) {
		std::cout << buffer[i] << " ";
	}
	std::cout << buffer << std::endl;
	releaseBuffer();
}

void CircBuffer::allocateBuffer(int size)
{ // check out malloc after this.

	buffer = new float[bufferSize];
	for (int i = 0; i < size; i++) {
		buffer[i] = 0;
	}
}

void CircBuffer::releaseBuffer()
{
	delete[] buffer;
	std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
		  << buffer << std::endl;
}

float CircBuffer::readHead()
{
	std::cout << "READHEAD READS: "<<buffer[readHeadPosition] << std::endl;
	return buffer[readHeadPosition];
}

void CircBuffer::writeHead(int currentSample)
{
	buffer[writeHeadPosition] = currentSample; // input
	std::cout << currentSample << std::endl;
}
