#include "rms.h"

Rms::Rms(int bufferSize)
{
				this-> bufferSize = bufferSize;
				std::cout << "initialising RMS buffer" << std::endl;
				buffer = new float[bufferSize];
}

Rms::~Rms()
{
				std::cout << "Removing the RMs buffer" << std::endl;
				delete[] buffer;
				buffer = nullptr;
}

float Rms::trackSignal(float incomingSignal)
{
				bufferPosition++;

				bufferSum += incomingSignal * incomingSignal;
				std::cout << "RmsSignal is: " << RMSSignal << std::endl;
				RMSSignal = sqrt(bufferSum / bufferPosition);
				return RMSSignal;
}

float Rms::resetRmsSize()
{
				RMSSignal = 0;
				std::cout << "shouldve reset RMS SIZE: " << RMSSignal << std::endl;
				return RMSSignal;
}
