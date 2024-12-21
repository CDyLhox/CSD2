#include "additiveSynth.h"

Additivesynth::Additivesynth(int additiveOption) : additiveOption(additiveOption)
{
    setAmplitudes();
    setExtraParameters(additiveOption);
}

Additivesynth::~Additivesynth()
{
}

void Additivesynth::setFrequencies(float frequency)
{

    for (int i = 0; i < MAXNUMSINES; i++)
    {
        // Use the user's extraParameter selection to select additivesynth preset.
        switch (additiveOption)
        {
        case 1:
            sines[i].setFrequency(frequency / 2 * i); // saw wave
            break;
        case 2:
            sines[i].setFrequency(frequency + i); // creeping BWAM
            break;
        case 3:
            sines[i].setFrequency(frequency - i); // Low Growl
            break;

        default:
            std::cout << "oops, something went horribly wrong" << std::endl;
            break;
        }
    }
}

void Additivesynth::setAmplitudes()
{
    for (int i = 0; i < MAXNUMSINES; i++)
    {
        // Use the user's extraParameter selection to select additivesynth preset.
        switch (additiveOption)
        {
        case 1:
            sines[i].setAmplitude(1.0 / (i + 1)); // saw wave
            break;
        case 2:
            sines[i].setAmplitude(1.0 * i); // creeping BWAM
            break;
        case 3:
            sines[i].setAmplitude(1.0 * (0.5 * i)); // Low Growl
            break;

        default:
            std::cout << "oops, something went horribly wrong" << std::endl;
            break;
        }
    }
}

float Additivesynth::getAllSamples()
{
    float sampleCalc = 0;
    for (int i = 0; i < MAXNUMSINES; i++) // actual num sines
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

int Additivesynth::setExtraParameters(int additiveOption)
{
    return (additiveOption);
}
