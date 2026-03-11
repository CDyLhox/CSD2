#ifndef CALLBACK_H
#define CALLBACK_H

#include "delay.h"
#include "waveshaper.h"
#include "tools/audiocomponent.h"
#include "tools/uiutility.h"

class CustomCallback : public AudioCallback {
    public:
	CustomCallback(float sampleRate);
	void prepare(int rate) override;
	void process(AudioBuffer buffer) override;

    private:
	float samplerate = 44100;
	Delay delay;
	Waveshaper waveshaper;

};

#endif // CALLBACK_H
