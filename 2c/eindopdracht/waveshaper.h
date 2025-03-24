#pragma once
#include "effect.h"
#include "rms.h"
#include <interpolation.h>
#include <iostream>
#include <math.h>

class Waveshaper : public Effect {

		public:
				Waveshaper();
				~Waveshaper();

				void applyEffect(const float& input, float& output) override;
				void setSlope(double slope);
				void fillBuffer();

		private:
				Rms rms { 4000 };
				// pirkle
				double m_slope = 1; // NOTE: this is the k value of the pirkle function
				float* m_waveTableBuffer;
				int m_bufferSize = 4086;
				float m_index;
				float m_sample;
};
