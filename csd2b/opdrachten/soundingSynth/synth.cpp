#include "synth.h"

Synth::Synth(float samplerate)
{
    sineOsc.setSamplerate(samplerate);
    squareOsc.setSamplerate(samplerate);
    sawOsc.setSamplerate(samplerate);
}

Synth::~Synth()
{
}

void Synth::tickAll()
{
    squareOsc.tick();
    sawOsc.tick();
    sineOsc.tick();
}

float Synth::getAllSamples()
{
    return (
        squareOsc.getSample(),
        sawOsc.getSample(),
        sineOsc.getSample());
}
// void synth::getSample(){

// }
