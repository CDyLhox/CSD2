#ifndef CALLBACK_H
#define CALLBACK_H

#include "delay.h"
#include "tremolo.h"
#include "waveshaper.h"
#include <audiocomponent.h>
#include <sine.h>

class CustomCallback : public AudioCallback {
    public:
	CustomCallback(float sampleRate);
	void prepare(int rate) override;
	void process(AudioBuffer buffer) override;

    private:
	float samplerate = 44100;
	Tremolo tremolo = Tremolo(6, 1);
	Delay delay;
	Waveshaper waveshaper;
	Sine testSine { 500, samplerate };
};

#endif // CALLBACK_H
