#pragma once

#include "allpass.h"
#include "circBuffer.h"
#include "delay.h"
#include "config.h"
#include "effect.h"

class Reverb : public Effect{
    public:
        void applyEffect( const float& input, float& output) override;
        void setDelayFeedback(float feedback);

        Reverb(float sr);
        ~Reverb();
float samplerate;
    private:
        Allpass allpass[numChannels][AMOUNT_OF_ALLPASS];
        Delay delay[numChannels][AMOUNT_OF_DELAYS];




};
