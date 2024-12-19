#ifndef _ADDITIVESYNTH_H_
#define _ADDITIVESYNTH_H_

#include <iostream>
#include "sine.h"

#define MAXNUMSINES 100

class Additivesynth
{
private:
    int numSines;
    Sine sines[MAXNUMSINES];


public:
    Additivesynth();
    ~Additivesynth();

    void setFrequencies(float frequency = 220.0);
    void setAmplitudes(); // actual number of sines 
    float getSamples();
    void tickAll();
};

#endif