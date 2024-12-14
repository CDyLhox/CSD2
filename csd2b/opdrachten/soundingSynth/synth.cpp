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
    Organsynth.tickAll(); // ciska wat vind jij? 
}

float Synth::getAllSamples()
{
    float allSamples = Organsynth.getSamples();
    // std::cout << "allsamples " << allSamples << std::endl;
    return allSamples;
}
// void synth::getSample(){

// }
