#pragma once

#include "allpass.h"
#include "circBuffer.h"
#include "delay.h"
#include "onepole.h"
#include "config.h"
#include "effect.h"

class Reverb : public Effect{
    public:
        void applyEffect( const float& input, float& output) override;
        void setDelayFeedback(float feedback);
        void setFreeze(bool state);

        Reverb(float sr);
        ~Reverb();
float samplerate;
    private:
        Allpass allpass[AMOUNT_OF_ALLPASS];
        Delay delay[AMOUNT_OF_DELAYS];
        Onepole onepole;
    
        bool freeze = false;
        float currentFeedback = 0.5f;



};
