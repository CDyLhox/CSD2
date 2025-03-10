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

	tremolo.setDryWet(0.5);
	waveshaper.setDryWet(0.5);
	delay.setDryWet(0.5);
	timestretcher.setDryWet(1);

	tremolo.setModFreq(9);
	waveshaper.setSlope(9999);
	delay.setNumDelaySamples(3);
	//granulator
}

void CustomCallback::process(AudioBuffer buffer)
{
	auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
	float sample;
	//NOTE: user input 
	for (int channel = 0u; channel < numInputChannels; channel++) {
		for (int i = 0u; i < numFrames; i++) {
			tremolo.processFrame(inputChannels[channel][i], sample);

			waveshaper.processFrame(sample, sample);//TODO: also make second sample variable
			delay.processFrame(sample, outputChannels[channel][i]);
		}
	}
}
