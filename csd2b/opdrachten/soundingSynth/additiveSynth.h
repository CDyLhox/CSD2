#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_

#include <iostream>
#include "sine.h"
#include "synth.h"

#define MAXNUMSINES 100

class Additivesynth : public Synth
{
private:
    int numSines;
    Sine sines[MAXNUMSINES];

public:
    Additivesynth();
    ~Additivesynth();

    // setamountofsines 
    // in de synth base class setparamiter void 

    void setFrequencies(float frequency = 220.0);
    void setAmplitudes(); // actual number of sines
    float getAllSamples();
    void tickAll();
};

#endif