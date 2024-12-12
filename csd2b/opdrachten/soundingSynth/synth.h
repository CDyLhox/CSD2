#ifndef SYNTH_H
#define SYNTH_H

#include "sine.h"
#include "square.h"
#include "saw.h"

class synth
{
private:


protected:

    Sine sineOsc{};
    Square squareOsc{};
    Saw sawOsc{};

public:
    synth(float samplerate = 44100);
    ~synth();

    void synth::tickAll();
    float synth::getAllSamples();
    // void synth::getSample();
};

#endif