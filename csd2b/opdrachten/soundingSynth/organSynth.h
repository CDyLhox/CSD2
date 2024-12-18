#ifndef _ORGANSYNTH_H_
#define _ORGANSYNTH_H_
#include <iostream>
#include "square.h"

class OrganSynth
{
private:
    /* data */
    Square OrganOne;
    Square OrganTwo;

public:
    OrganSynth(/* args */);
    ~OrganSynth();

    float getAllSamples();
    void setFrequencies(float frequency = 220.0);
    void tickAll();
};

#endif