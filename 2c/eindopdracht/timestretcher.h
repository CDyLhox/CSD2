#pragma once

#include "delay.h"
#include "effect.h"
#include <iostream>

class Timestretcher : public Effect {
		public:
				// appies the delay effect as a timestretcher
				void applyEffect(const float &input, float &output) override;	
				// set the amount of time the inputSig has to cross the 0 before the circbuffer repeats
				void setAmountZeroCrossings(uint timeStretchLength);
				//TODO: MAYBE SET FEEDBAKC
				//void setFeedback

		protected:

				Delay acircbuffer;

				int m_NumZeroCrossings = 0;
		private:
				

};
