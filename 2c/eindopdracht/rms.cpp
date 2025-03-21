#include "rms.h"

Rms::Rms(int bufferSize)
{
				std::cout << "initialising RMS buffer" << std::endl;
}

Rms::~Rms()
{
}

float Rms::trackSignal(float incomingSignal)
{
				bufferPosition++;

				bufferSum += incomingSignal * incomingSignal;
				RMSSignal = sqrt(bufferSum / bufferPosition);

				return RMSSignal;
}

float Rms::resetRmsSize()
{
				bufferSum = 0;
				RMSSignal = 0;
				bufferPosition = 0;
				return RMSSignal;
}
