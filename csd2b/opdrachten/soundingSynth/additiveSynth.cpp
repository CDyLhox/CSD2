#include "additiveSynth.h"

Additivesynth::Additivesynth()
{

    std::cout << "additivesynth::additive synth - {PLUSPLUSPLUSPLUSetc}" << std::endl;
}

Additivesynth::~Additivesynth()
{
    std::cout << "additivesynth::additivesynth - DESTRUCTOR MINMINMINMINMINetc" << std::endl;
}

void Additivesynth::setFrequencies(float frequency)
{

    for (int i = 0; i < MAXNUMSINES; i++)
    {
        sines[i].setFrequency(frequency / 2 * i); // saw wave
    }
}

void Additivesynth::setAmplitudes()
{
    for (int i = 0; i < MAXNUMSINES; i++)
    {
        sines[i].setAmplitude(2.0 / (i + 1));
    }
}

float Additivesynth::getSamples()
{
    float sampleCalc = 0;
    for (int i = 0; i < MAXNUMSINES; i++)
    {
        sampleCalc = sampleCalc + (sines[i].getSample()) / MAXNUMSINES; // actual num sines
    }
    return sampleCalc;
}

void Additivesynth::tickAll()
{
    for (int i = 0; i < 100; i++)
    {
        sines[i].tick();
    }
}
