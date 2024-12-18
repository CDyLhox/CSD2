#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "organSynth.h"
#include "additiveSynth.h"

#include "sine.h"
#include "square.h"
#include "saw.h"

class Synth
{
private:
protected:
    Sine sineOsc;
    Square squareOsc;
    Saw sawOsc;
    OrganSynth Organsynth;
    Additivesynth AdditiveSynth;

public:
    // virtual
    Synth(float samplerate);
    ~Synth();

    virtual void tickAll();
    virtual float getAllSamples();
    void setFrequencies(float freq);
    // void synth::getSample();
};

#endif