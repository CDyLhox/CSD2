#ifndef _ORGANSYNTH_H_
#define _ORGANSYNTH_H_

#include <iostream>

#include "square.h"
#include "synth.h"

class OrganSynth : public Synth
{
private:

    Square OrganOne;
    Square OrganTwo;

public:
    OrganSynth();
    ~OrganSynth();

    float getAllSamples() override;
    void setFrequencies(float frequency = 220.0) override;
    void tickAll() override;
    void setAmplitudes(); 
};

#endif