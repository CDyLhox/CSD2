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
	tremolo.setBypass(1);
	waveshaper.setBypass(1);
	delay.setBypass(1);
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
