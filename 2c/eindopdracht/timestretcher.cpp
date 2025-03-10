#include "timestretcher.h"

Timestretcher::Timestretcher()
{
				std::cout << "Timestretcher::timestretcher" << std::endl;
				circBuffer(2000, 500); // 2000 samples buffersize, 500 numsamplesdelay
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
				//.processFrame(input, output);// TODO  MAKE PROCESSFRAME FOR CIRCBUFFER
				trackBufferSize(input);
				writeHead(input);
				incrementWriteHead();
				std::cout << bufferSize << std::endl;
				std::cout << "writeheadpostion" << writeHeadPosition << std::endl;

}

void Timestretcher::setAmountZeroCrossings(int timeStretchLength)
{ // TODO: safety checks: check if the number is devisable by 2 else correct the number upwards (dc offset)
				m_maxNumZeroCrossings = timeStretchLength;
				// circbuffer.setNumDelaySamples(5);
}

void Timestretcher::prepare()
{
}


float Timestretcher::trackBufferSize(const float& input)
{
				//
				prevSample = sample;
				sample = input;
				m_zeroCrossingTimer++;

				// if goes from positive to negative yknow 2 if statements :
				// XOR
				// bool prevsample positive
				// bool cursamplepos
				// coment
				// if ((prev >= 0) != (cur >=0))
				if ((prevSample >= 0) != (sample >= 0)) {
								m_NumZeroCrossings++;
								std::cout << "crossed 0 : " << m_NumZeroCrossings << "amount of times" << std::endl;
				}
				if (m_NumZeroCrossings == m_maxNumZeroCrossings) {
								std::cout << m_zeroCrossingTimer << " amount of zerocrossings" << std::endl;
								m_NumZeroCrossings = 0;
								m_zeroCrossingTimer = 0;
				}
				return m_zeroCrossingTimer;
}

// ______________________ CIRCBUFFER _______________________

void Timestretcher::circBuffer(int size, int numSamplesDelay)
{
				// Dynamic array
				std::cout << "numSamplesDelay: " << numSamplesDelay << std::endl;
				bufferSize = size;
				writeHeadPosition = numSamplesDelay;
				allocateBuffer(size);
}

void Timestretcher::allocateBuffer(int size)
{ // check out malloc after this.

				buffer = new float[size];
				for (int i = 0; i < size; i++) {
								buffer[i] = 0;
				}
}

void Timestretcher::releaseBuffer()
{
				delete[] buffer;
				buffer = nullptr;
				std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
									<< buffer << std::endl;
}

float Timestretcher::readHead()
{
				std::cout << "READHEAD READS: " << buffer[readHeadPosition] << std::endl;
				return buffer[readHeadPosition];
}

void Timestretcher::writeHead(int currentSample)
{
				buffer[writeHeadPosition] = currentSample; // input
				std::cout << currentSample << std::endl;
}

void Timestretcher::setDelayTime(int numSamplesDelay)
{ // take current writeheadPosition and last numSamplesDelay setting.
				// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
				//
				// I DONT AGREE
				//
				// move the buffer right of where the buffer was.
				readHeadPosition = writeHeadPosition;
				writeHeadPosition = numSamplesDelay;
}

void Timestretcher::setDelayTime(float miliSecondsDelay)
{
				// SAMPLERATE / (miliSecondsDelay/1000)
}
