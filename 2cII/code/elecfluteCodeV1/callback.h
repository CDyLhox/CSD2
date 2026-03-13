#ifndef CALLBACK_H
#define CALLBACK_H

#include "delay.h"
#include "waveshaper.h"
#include "tools/audiocomponent.h"
#include "tools/uiutility.h"
#include <osc_server.h>
#include "allpass.h"

class CustomCallback : public AudioCallback {
    public:
        CustomCallback(float sampleRate);
        void prepare(int rate) override;
        void process(AudioBuffer buffer) override;

    private:
        float samplerate = 44100;
        Delay delay;
        Waveshaper waveshaper;
        Allpass allpass;

        float targetParameter { 440.f };
        LocalOSC oscServer { targetParameter };
        std::string serverport {"7777"};
};

#endif // CALLBACK_H
