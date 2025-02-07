#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_

#include <iostream>
#include "sine.h"
#include "synth.h"

#define MAXNUMSINES 100

class Additivesynth : public Synth
{
private:
    Sine sines[MAXNUMSINES];

public:
    int additiveOption;

    Additivesynth(int additiveOption);
    ~Additivesynth();

    // setamountofsines
    // in de synth base class setparamiter void

    // initialise the additivesynth with a standard frequency.
    void setFrequencies(float frequency = 220.0) override;
    // set the amplitude of the oscilltors based on the amount of oscilltors in use
    void setAmplitudes();
    // return the sum of all of the active samples to the callback and tick all sine oscilltors
    float getAllSamples() override;
    void tickAll() override;

    // the sauce of the synth.
    // choose between a few different addition alogithms
    int setExtraParameters(int additiveOption) override;
};

#endif