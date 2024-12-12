#include "synth.h"

synth::synth(float samplerate = 44100)
{
    sineOsc.setSamplerate(samplerate);
    squareOsc.setSamplerate(samplerate);
    sawOsc.setSamplerate(samplerate);
}

synth::~synth()
{
}

void synth::tickAll()
{
    squareOsc.tick();
    sawOsc.tick();
    sineOsc.tick();
}

float synth::getAllSamples()
{
    squareOsc.tick();
    sawOsc.tick();
    sineOsc.tick();
}
// void synth::getSample(){

// }
