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

                // zet hier ff je bypass

				waveshaper.setBypass(true);
				delay.setBypass(false);
                allpass.setBypass(false);

				waveshaper.setDryWet(1);
				delay.setDryWet(0.5);
				delay.setFeedback(1);
                delay.setNumDelaySamples(4000);
                allpass.setDryWet(1);

				waveshaper.setSlope(0.5);

}

void CustomCallback::process(AudioBuffer buffer)
{
				auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
				float sample1;
				float sample2;
				// NOTE: user input
				for (int channel = 0u; channel < numInputChannels; channel++) {
								for (int i = 0u; i < numFrames; i++) {
                                    delay.processFrame(inputChannels[channel][i], sample1);
                                    allpass.processFrame(sample1, outputChannels[channel][i]);
								}
				}
}
