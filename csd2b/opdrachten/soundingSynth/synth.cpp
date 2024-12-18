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
    AdditiveSynth.tickAll();
}

float Synth::getAllSamples()
{
    float samples = AdditiveSynth.getSamples();
    return samples;
}


void Synth::setFrequencies(float freq)
{
    Organsynth.setFrequencies(freq);
    AdditiveSynth.setFrequencies(freq);
}
