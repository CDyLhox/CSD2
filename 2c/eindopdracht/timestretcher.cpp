#include "timestretcher.h"

Timestretcher::Timestretcher()
{
				std::cout << "Timestretcher::timestretcher" << std::endl;
}
Timestretcher::~Timestretcher()
{
				std::cout << "Timestretcher::~timestretcher" << std::endl;
}

void Timestretcher::applyEffect(const float& input, float& output)
{
				circbuffer.processFrame(input, output);
				trackBufferSize(input);
}

void Timestretcher::setAmountZeroCrossings(int timeStretchLength)
{//TODO: safety checks: check if the number is devisable by 2 else correct the number upwards (dc offset)
				m_maxNumZeroCrossings = timeStretchLength;
				//circbuffer.setNumDelaySamples(5);
}

void Timestretcher::prepare()
{
				circbuffer.setDryWet(1);
				circbuffer.setBypass(false);
}

float Timestretcher::trackBufferSize(const float& input)
{
				m_zeroCrossingTimer++;
				if (input == 0) {
								m_NumZeroCrossings++;
				}
				if(m_NumZeroCrossings == m_maxNumZeroCrossings){
				std::cout << m_zeroCrossingTimer << " amount of zerocrossings" << std::endl;
				}
}
