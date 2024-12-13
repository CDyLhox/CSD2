#ifndef SYNTH_H
#define SYNTH_H

#include "sine.h"
#include "square.h"
#include "saw.h"

class Synth
{
private:
protected:
    Sine sineOsc{};
    Square squareOsc{};
    Saw sawOsc{};

public:
    Synth(float samplerate);
    ~Synth();

    void tickAll();
    float getAllSamples();
    // void synth::getSample();
};

#endif