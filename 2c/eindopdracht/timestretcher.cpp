#include "timestretcher.h"

Timestretcher::Timestretcher()
{
				std::cout << "Timestretcher::timestretcher" << std::endl;
				circBuffer(10000, 500); // 2000 samples buffersize, 500 numsamplesdelay
}
Timestretcher::~Timestretcher()
{
				std::cout << "Timestretcher::~timestretcher" << std::endl;
				std::cout << "CircBuffer::~circBuffer \n"
									<< "Elements of the Buffer were: ";
				for (int i = 0; i < 512; i++) {
								std::cout << "\033[32m" << buffer[i] << "\033[0m" << " ";
				}
				std::cout << buffer << std::endl;

				std::cout << "Elements of the loopBuffer were: ";
				for (int i = 0; i < 512; i++) {
								std::cout << "\033[34m" << m_loopBuffer[i] << "\033[0m" << " ";
				}
				std::cout << buffer << std::endl;

				std::cout << "readhead pos was: " << readHeadPosition << "\nwritehead pos was: " << writeHeadPosition << std::endl;
				releaseBuffer();
}

void Timestretcher::applyEffect(const float& input, float& output)
{
				std::cout << "Timestretcher::applyeffect" << std::endl;
				trackBufferSize(input);
				writeHead(input);
				incrementWriteHead();

				output = readLoopHead();
				incrementLoopReadHead();

				prepare(input);
}
void Timestretcher::prepare(const float& input)
{
				std::cout << "TimeStretcher::Prepare to be amazed\n";
				clock++;
				if (clock > 9000) { // FIXME this is an interesting parameter. lfo rate.


								// Note: copy the loop from the big buffer to the loopBuffer
								//std::cout << "Timesteretechter:: prepare; for loop\n";
								for (int i = 0; i < m_loopSize; i++) {
												//write
												writeLoopHead(readHead());
												incrementLoopWriteHead();

												incrementReadHead();
								}

								readHeadPosition = 0;
								m_NumZeroCrossings = 0;
								m_zeroCrossingTimer = 0;
								clock = 0;
				}
}

void Timestretcher::setAmountZeroCrossings(int timeStretchLength)
{ // TODO: safety checks: check if the number is devisable by 2 else correct the number upwards (dc offset)
				std::cout << "Timestretcher::setAmountZeroCrossings be like\n";
				m_maxNumZeroCrossings = timeStretchLength;
				// circbuffer.setNumDelaySamples(5);
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
				}
				if (m_NumZeroCrossings == m_maxNumZeroCrossings) {
								std::cout << "crossed 0 : " << m_NumZeroCrossings << "amount of times" << std::endl;
								std::cout << m_zeroCrossingTimer << " time between zerocrossings" << std::endl;

								setDelayTime(m_zeroCrossingTimer);

								// Update ReadheadPosition based on how long the zerocrossingstimer says the amount of zerocrossings took
								// TODO: readheadPOstiion = writeheadposition - m_zerocrossingstimer
								writeHeadPosition = m_zeroCrossingTimer;
								m_loopSize = m_zeroCrossingTimer;
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
{

				buffer = new float[size];
				for (int i = 0; i < size; i++) {
								buffer[i] = 0;
				}

				std::cout << "allocateLoopBuffer" << std::endl;

				// the size of the buffers are the same but the loopbuffer doesn't need to write constantly
				m_loopBuffer = new float[size];
				for (int i = 0; i < size; i++) {
								m_loopBuffer[i] = 0;
				}
}

void Timestretcher::releaseBuffer()
{
				delete[] buffer;
				buffer = nullptr;
				std::cout << "circBuffer::releaseBuffer; i am releasing the buffer: "
									<< buffer << std::endl;

				
				delete[] m_loopBuffer;
				buffer = nullptr;
				std::cout << "Releasing Loop Buffer" << std::endl;
}

float Timestretcher::readHead()
{
				return buffer[readHeadPosition];
}

void Timestretcher::writeHead(float currentSample)
{
				buffer[writeHeadPosition] = currentSample; // input
}

void Timestretcher::writeLoopHead(float currentSample)
{
				std::cout << "timestretcher::writeloophead the writing of a loophead" << std::endl;
				m_loopBuffer[m_writeLoopHeadPosition] = currentSample;
}

float Timestretcher::readLoopHead()
{
				//std::cout << "Timestretcher::ReadLoopHead" << std::endl;
				return m_loopBuffer[m_readLoopHeadPosition];
}

void Timestretcher::setDelayTime(int numSamplesDelay)
{ // take current writeheadPosition and last numSamplesDelay setting.
				// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
				//
				// I DONT AGREE
				//
				// move the buffer right of where the buffer was.
				//
				// readHeadPosition = writeHeadPosition - numSamplesDelay; TODO: AFTER FIXING THE LOOP
				readHeadPosition = 0;
				writeHeadPosition = numSamplesDelay;
}
