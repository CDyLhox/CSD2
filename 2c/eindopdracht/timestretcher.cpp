#include "timestretcher.h"

Timestretcher::Timestretcher()
{
				std::cout << "Timestretcher::timestretcher" << std::endl;
}
Timestretcher::~Timestretcher()
{
				std::cout << "Timestretcher::~timestretcher" << std::endl;
				std::cout << "CircBuffer::~circBuffer \n"
									<< "Elements of the array were: ";
				for (int i = 0; i < 512; i++) {
								std::cout << buffer[i] << " ";
				}
				std::cout << buffer << std::endl;
				releaseBuffer();
}

void Timestretcher::applyEffect(const float& input, float& output)
{
				circbuffer.processFrame(input, output);
				trackBufferSize(input);
				prevSample = input;
}

void Timestretcher::setAmountZeroCrossings(int timeStretchLength)
{ // TODO: safety checks: check if the number is devisable by 2 else correct the number upwards (dc offset)
				m_maxNumZeroCrossings = timeStretchLength;
				// circbuffer.setNumDelaySamples(5);
}

void Timestretcher::prepare()
{
				circbuffer.setDryWet(1);
				circbuffer.setBypass(false);
}

float Timestretcher::trackBufferSize(const float& input)
{
				m_zeroCrossingTimer++;
				// if goes from positive to negative yknow 2 if statements :
				// XOR
				// bool prevsample positive
				// bool cursamplepos
				// coment
				// if ((prev >= 0) != (cur >=0))
				if ((prevSample >= 0) != (currentSample >= 0)) {
								m_NumZeroCrossings++;
								std::cout << "crossed 0 : " << m_NumZeroCrossings << "amount of times" << std::endl;
				}
				if (m_NumZeroCrossings == m_maxNumZeroCrossings) {
								std::cout << m_zeroCrossingTimer << " amount of zerocrossings" << std::endl;
				}
}

// ______________________ CIRCBUFFER _______________________

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
				buffer = nullptr;
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
{ // take current writeheadPosition and last numSamplesDelay setting.
				// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
				writeHeadPosition;
}
void setDelayTime(float miliSecondsDelay)
{
				// SAMPLERATE / (miliSecondsDelay/1000)
}
