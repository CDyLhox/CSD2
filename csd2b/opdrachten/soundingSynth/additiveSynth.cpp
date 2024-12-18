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
        sines[i].setFrequency(frequency * i / 2); // bedenk hier iets voor
         // bedenk hier iets voor
    }
}

void Additivesynth::setAmplitudes(float devision)
{
    for (int i = 0; i < MAXNUMSINES; i++)
    {
        sines[i].setAmplitude(i / devision);
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
