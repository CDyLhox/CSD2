#pragma once

#include "delay.h"
#include "effect.h"
#include <iostream>

class Timestretcher : public Effect {
		public:
				Timestretcher();
				~Timestretcher();

				// appies the delay effect as a timestretcher
				void applyEffect(const float& input, float& output) override;
				// set the amount of time the inputSig has to cross the 0 before the circbuffer repeats
				void setAmountZeroCrossings(int timeStretchLength);
				// TODO: MAYBE SET FEEDBAKC
				// void setFeedback

				// use the numZeroCrossings to fill buffer
				void prepare();
				float trackBufferSize(const float& input);

		protected:
		private:
				Delay circbuffer; // implement parts directly into the timestretcher from circular buffer

				int m_NumZeroCrossings = 0;
				int m_maxNumZeroCrossings = 2;
				int m_zeroCrossingTimer = 0;
				float prevSample = 0;
				float currentSample = 0;

				//CIRCBUFFER STUFF
					void CircBuffer();
	void CircBuffer(int bufferSize, int numSamplesDelay);
	void deleteCircBuffer();
	float* buffer;
	float readHead();
	void writeHead(int currentSample);
	void allocateBuffer(int size);
	void releaseBuffer();

	void setDelayTime(int numSamplesDelay);
	void setDelayTime(float miliSecondsDelay);

	inline void tick()
	{
		std::cout << "tick" << std::endl;
		incrementWriteHead();
		incrementReadHead();

		std::cout << "readHeadPosition" << readHeadPosition << std::endl;
		std::cout << "writeHeadPosition" << writeHeadPosition << std::endl;
	}

    private:
	uint bufferSize = 200;
	uint currentSample = 0;
	int numSamplesDelay;
	float miliSecondsDelay;

	uint rWDistance = 0;
	uint readHeadPosition = 0;
	uint writeHeadPosition = 10;

	inline void incrementWriteHead()
	{
		writeHeadPosition++;
		wrapHeads(writeHeadPosition);
	}
	inline void incrementReadHead()
	{
		readHeadPosition++;
		wrapHeads(writeHeadPosition);
	}
	inline void wrapHeads(uint head)
	{
		if (head >= bufferSize) {
			head -= bufferSize;
		}
	}

};
//
