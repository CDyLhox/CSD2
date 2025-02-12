#include "circBuffer.h"

CircBuffer::CircBuffer()
    : CircBuffer(200, 500)
{
} // set default constructor
CircBuffer::CircBuffer(int size, int numSamplesDelay)
{
	// Dynamic array
	std::cout << "numSamplesDelay: " << numSamplesDelay << std::endl;
	bufferSize = size;
	writeHeadPosition = numSamplesDelay;
	allocateBuffer(size);
}

CircBuffer::~CircBuffer()
{
	std::cout << "CircBuffer::~circBuffer \n"
		  << "Elements of the array were: ";
	for (int i = 0; i < 512; i++) {
		std::cout << buffer[i] << " ";
	}
	std::cout << buffer << std::endl;
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
	std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
		  << buffer << std::endl;
}

float CircBuffer::readHead()
{
	std::cout << "READHEAD READS: " << buffer[readHeadPosition] << std::endl;
	return buffer[readHeadPosition];
}

void CircBuffer::writeHead(int currentSample)
{
	buffer[writeHeadPosition] = currentSample; // input
	std::cout << currentSample << std::endl;
}
void setDelayTime(int numSamplesDelay)
{ 	// take current writeheadPosition and last numSamplesDelay setting.
	// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
	writeHeadPosition;
}
void setDelayTime(float miliSecondsDelay) {
	//SAMPLERATE / (miliSecondsDelay/1000) 

}
