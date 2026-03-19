#ifndef CALLBACK_H
#define CALLBACK_H

#include "delay.h"
#include "waveshaper.h"
#include "tools/audiocomponent.h"
#include "tools/uiutility.h"
#include <osc_server.h>
#include "allpass.h"
#include "reverb.h"
#include "config.h"
#include "onepole.h"

class CustomCallback : public AudioCallback {
    public:
        CustomCallback(float sampleRate);
        void prepare(int rate) override;
        void process(AudioBuffer buffer) override;

        float samplerate = 44100;
    private:
        Waveshaper waveshaper;
        //Reverb reverb{samplerate};
        std::vector<Reverb> reverbs;
        Onepole onepole;
        float targetParameter { parameterInit };
        LocalOSC oscServer { targetParameter };
        std::string serverport {"7777"};
        float lastParameter = 0;
};

#endif // CALLBACK_H
