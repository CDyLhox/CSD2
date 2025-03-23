#ifndef CALLBACK_H
#define CALLBACK_H

#include "delay.h"
#include "tremolo.h"
#include "waveshaper.h"
#include <audiocomponent.h>
#include "uiutility.h"
#include "timestretcher.h"

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
	Timestretcher timestretcher;

};

#endif // CALLBACK_H
