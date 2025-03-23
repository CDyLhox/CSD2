#include "rms.h"

Rms::Rms(int bufferSize)
{
				this->bufferSize = bufferSize;
				std::cout << "initialising RMS" << std::endl;
				
}

Rms::~Rms()
{
}

float Rms::trackSignal(float incomingSignal)
{
				bufferPosition++;

				bufferSum += incomingSignal * incomingSignal;
				RMSSignal = sqrt(bufferSum / bufferPosition);

				if(bufferPosition > bufferSize){resetRmsSize();}
				return RMSSignal;
}

float Rms::resetRmsSize()
{
				std::cout << "resetting rms window " << std::endl;
				bufferSum = 0;
				RMSSignal = 0;
				bufferPosition = 0;
				return RMSSignal;
}
