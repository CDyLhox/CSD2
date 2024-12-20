#include "organSynth.h"

OrganSynth::OrganSynth()
{
    std::cout << "organsynth::organsynth - i think therefore i am an organsynth" << std::endl;
}

OrganSynth::~OrganSynth()
{
    std::cout << "organsynth::organsynth - i am no more organsynth than you are" << std::endl;
}

void OrganSynth::setFrequencies(float frequency)
{
    OrganOne.setFrequency(frequency);
    OrganTwo.setFrequency(frequency * 1.5);
}

float OrganSynth::getAllSamples()
{
    float allSamples = (OrganOne.getSample() + OrganTwo.getSample()) / 2;
    return allSamples;
}



void OrganSynth::tickAll()
{

    OrganOne.tick(); // zet dit misschien in de synth
    OrganTwo.tick();
}