#include "synth.h"

Synth::Synth(float samplerate)
{
    sineOsc.setSamplerate(samplerate);
    squareOsc.setSamplerate(samplerate);
    sawOsc.setSamplerate(samplerate);
    std::cout << "synth::synth - Synth i am a SYNTH" << std::endl;
}

Synth::~Synth()
{
    std::cout << "synth::synth - synths i am no more a synth" << std::endl;
}

void Synth::tickAll()
{
    std::cout << "i am ticking all" << std::endl;
    sineOsc.tick();
    squareOsc.tick();
    sawOsc.tick();
}

float Synth::getAllSamples()
{
    float allSamples = squareOsc.getSample() +
                       sawOsc.getSample() +
                        sineOsc.getSample();
    std::cout << "allsamples " << allSamples << std::endl;
    return allSamples;
}
// void synth::getSample(){

// }
