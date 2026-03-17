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
        static const int AMOUNT_OF_ALLPASS = 100;
        static const int AMOUNT_OF_DELAYS = 4;
        static const int numChannels = 2;
        float samplerate = 44100;

        Waveshaper waveshaper;
        Allpass allpass[numChannels][AMOUNT_OF_ALLPASS];
        Delay delay[numChannels][AMOUNT_OF_DELAYS];

        float targetParameter { 0.8f };
        LocalOSC oscServer { targetParameter };
        std::string serverport {"7777"};
};

#endif // CALLBACK_H
