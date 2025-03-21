#pragma once

#include "delay.h"
#include "effect.h"
#include "rms.h"
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
				// TODO: BPM INTEREGRATION
				//TODO: interpolatie toevoegen om clicks te voorkomen -- maybe
				//TODO variable buffer length -- multiple buffers for overlap of buffers 

				// use the numZeroCrossings to fill buffer
				void prepare(const float &input);
				void trackBufferSize(const float& input, int &m_zeroCrossingTimer);
				void fillBuffer(const float& input);

		protected:
		private:

				Rms rms{3000};

				// Delay circbuffer; // implement parts directly into the timestretcher from circular buffer
				//
				int clock = 0; 
				int nextClock;

				int m_NumZeroCrossings = 0;
								int m_maxNumZeroCrossings = 128;//FIXME interesting parameter, maxnumzerocrossings
				int m_zeroCrossingTimer = 0;
				float prevSample = 0;
				float sample = 0;
				float m_rmsSignal = 0;

				// CIRCBUFFER STUFF
				void circBuffer(int bufferSize, int numSamplesDelay);
				float readHead();
				void writeHead(float currentSample);

				void writeLoopHead(float currentSample);
				float readLoopHead();


				// Buffer Stuffer 
				float* buffer;
				float* m_loopBuffer;
				void allocateBuffer(int size);
				
				void releaseBuffer();
				void releaseLoopBuffer();




				void setDelayTime(int numSamplesDelay);

				inline void tick()
				{
								std::cout << "tick" << std::endl;
								incrementWriteHead();
								incrementReadHead();

								std::cout << "readHeadPosition" << readHeadPosition << std::endl;
								std::cout << "writeHeadPosition" << writeHeadPosition << std::endl;
				}

				uint bufferSize = 200;
				float currentSample;
				int numSamplesDelay;
				float miliSecondsDelay;

				uint readHeadPosition = 0;
				uint writeHeadPosition = 10;


				uint m_readLoopHeadPosition = 0;
				uint m_writeLoopHeadPosition = 0;


				uint m_loopSize = bufferSize;
				uint m_loopSizeLast = 0;

				inline void incrementWriteHead()
				{
								writeHeadPosition++;
								//std::cout << "writeheadpostiin" << writeHeadPosition << std::endl;
								wrapHeads(writeHeadPosition);
				}
				inline void incrementReadHead()
				{
								readHeadPosition++;
								//std::cout << "readheadposition" << readHeadPosition << std::endl;
								
								wrapHeads(readHeadPosition);
				}
				inline void wrapHeads(uint& head)
				{

							/*	if (readHeadPosition >= m_loopSize) {//writehead = readhead+loopsize
												head -= m_loopSize;
												std::cout << "LOWKEY wrapping head ( loopsize ) \n"
																	<< "loopsize" << m_loopSize << "\n";
								}*/	if (head >= bufferSize) {
												head -= bufferSize;
												//std::cout << "-------------------- Timestretcher::WrapHeads" << "head" << head << std::endl;
								}
				}


				inline void incrementLoopWriteHead()
				{
								m_writeLoopHeadPosition++;
								//std::cout << "timestretcher::incrementLoopWriteHead" << writeHeadPosition << std::endl;
								wrapLoopHeads(m_writeLoopHeadPosition);
				}
				inline void incrementLoopReadHead()
				{
								m_readLoopHeadPosition++;
								//std::cout << "readheadposition" << readHeadPosition << std::endl;
								
								wrapLoopHeads(m_readLoopHeadPosition);
				}
				inline void wrapLoopHeads(uint& head)
				{

								if (head >= m_loopSize) {//writehead = readhead+loopsize
												head -= m_loopSize;
												//std::cout << "LOWKEY wrapping head ( loopsize ) \n"
																	//<< "loopsize" << m_loopSize << "\n";
								}else if (head >= bufferSize) {
												head -= bufferSize;
												//std::cout << "HIGHKEY wrapping head( buffersize )" << "loopsize" << m_loopSize << std::endl;
								}
				}
};
//
