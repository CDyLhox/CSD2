#include "callback.h"

CustomCallback::CustomCallback(float sampleRate)
		: AudioCallback(sampleRate)
		, samplerate(sampleRate)
{
}

void CustomCallback::prepare(int rate)
{

				samplerate = (float)rate;
				std::cout << "\nsamplerate: " << samplerate << "\n";

				tremolo.prepare(rate);
				// location for bypasses
				timestretcher.setBypass(false);
				tremolo.setBypass(true);
				waveshaper.setBypass(true);
				delay.setBypass(true);

				tremolo.setDryWet(0.6);
				waveshaper.setDryWet(1);
				delay.setDryWet(1);
				timestretcher.setDryWet(1);

				tremolo.setModFreq(9);
				waveshaper.setSlope(0.5);
				delay.setNumDelaySamples(4000);
				// granulator
}

void CustomCallback::process(AudioBuffer buffer)
{
				auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
				float sample1;
				float sample2;
				// NOTE: user input
				for (int channel = 0u; channel < numInputChannels; channel++) {
								for (int i = 0u; i < numFrames; i++) {
												timestretcher.processFrame(inputChannels[channel][i], outputChannels[channel][i]);
											/*tremolo.processFrame(sample1, sample2);
												delay.processFrame(sample2, sample1);

												waveshaper.processFrame(sample1, outputChannels[channel][i]); */

								}
				}
}
