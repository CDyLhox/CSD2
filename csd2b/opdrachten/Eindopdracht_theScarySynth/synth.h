#ifndef _SYNTH_H_
#define _SYNTH_H_


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
    float mtof(float mPitch);
    void updatePitch(Melody &melody);

    virtual int setExtraParameters(int parameterz);



};

#endif