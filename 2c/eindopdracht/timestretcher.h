#pragma once

#include "delay.h"
#include "effect.h"
#include <iostream>

class Timestretcher : public Effect {
		public:
				Timestretcher();
				~Timestretcher();
				

				// appies the delay effect as a timestretcher
				void applyEffect(const float &input, float &output) override;	
				// set the amount of time the inputSig has to cross the 0 before the circbuffer repeats
				void setAmountZeroCrossings(int timeStretchLength);
				//TODO: MAYBE SET FEEDBAKC
				//void setFeedback
				
				// use the numZeroCrossings to fill buffer
				void prepare();
				float trackBufferSize(const float &input);

		protected:

		private:
				
				Delay circbuffer;

				int m_NumZeroCrossings = 0;
				int m_maxNumZeroCrossings = 2;
				int m_zeroCrossingTimer = 0;
};
