#ifndef _SAW_H_
#define _SAW_H_
#include "oscillator.h"

class Saw : public Oscillator
{

public:
    Saw(float frequency = 270, float samplerate = 44100);
    ~Saw();

    void calculate();
};

#endif