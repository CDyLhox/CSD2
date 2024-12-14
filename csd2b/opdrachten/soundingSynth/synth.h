#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "organSynth.h"

#include "sine.h"
#include "square.h"
#include "saw.h"

class Synth
{
private:
protected:
    OrganSynth Organsynth;


    Sine sineOsc;
    Square squareOsc;
    // Square squareOsc{345, 44100};
    Saw sawOsc;

public:
    // virtual 
    Synth(float samplerate);
    ~Synth();

    void tickAll();
    float getAllSamples();
    // void synth::getSample();
};

#endif