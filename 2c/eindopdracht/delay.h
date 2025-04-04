#pragma once
#include "effect.h"
#include "rms.h"

class Delay : public Effect {
		public:
				Delay(float feedback = 0.7, uint numDelaySamples = 4099,
						uint maxDelaySize = 4100, float dryWet = 1.0);
				~Delay();

				// override base class method
				// applies delay effect to the input frame and stores it to the output frame
				void applyEffect(const float& input, float& output) override;

				// sets the number of samples to delay
				void setNumDelaySamples(uint numDelaySamples);
				// sets the feedback value, should be in range [0, 1]
				void setFeedback(float feedback);

		private:
				inline void wrapH(uint& head)
				{
								if (head >= m_size)
												head -= m_size;
				}

				float m_feedback = 0.0f;

				// maxDelaySize
				Rms rms { 9000 };
				float m_rmsSignal;
				// circular buffer variables
				// pointer to the buffer
				float* m_buffer;
				// num samples to delay
				uint m_numDelaySamples;
				// buffer size
				uint m_size;
				// read and write heads, delay size
				uint m_readH;
				uint m_writeH;
};
