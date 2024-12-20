#ifndef _SYNTH_H_
#define _SYNTH_H_

#include "sine.h"
#include "square.h"
#include "saw.h"

#include "melody.h"

class Synth
{
private:
protected:

public:
    // virtual
    Synth();
    ~Synth();

    virtual void tickAll();
    virtual float getAllSamples();
    virtual void setFrequencies(float freq) = 0;
    // void synth::getSample();
    double mtof(float mPitch);
    void updatePitch(Melody &melody);
};

#endif