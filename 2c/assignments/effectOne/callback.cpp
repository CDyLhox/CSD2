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
	tremolo.setBypass(false);
	waveshaper.setBypass(true);
	delay.setBypass(true);

	tremolo.setDryWet(0.5);
	waveshaper.setDryWet(0.5);
	delay.setDryWet(0.5);

	tremolo.setModFreq(49);
	waveshaper.setSlope(9999);
	delay.setNumDelaySamples(3);
	
}

void CustomCallback::process(AudioBuffer buffer)
{
	auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
	float sample;
	for (int channel = 0u; channel < numInputChannels; channel++) {
		for (int i = 0u; i < numFrames; i++) {
			tremolo.processFrame(inputChannels[channel][i], sample);

			waveshaper.processFrame(sample, sample);
			delay.processFrame(sample, outputChannels[channel][i]);
		}
	}
}
