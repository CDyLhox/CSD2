#include "organSynth.h"

OrganSynth::OrganSynth(/* args */)
{
    std::cout << "organsynth::organsynth - i think therefore i am an organsynth" << std::endl;
    setFrequencies();
}

OrganSynth::~OrganSynth()
{
    std::cout << "organsynth::organsynth - i am no more organsynth than you are" << std::endl;
}

void OrganSynth::setFrequencies(float frequency)
{
    std::cout << "IUGHM" << std::endl;
    OrganOne.setFrequency(frequency);
    OrganTwo.setFrequency(frequency * 1.5);
}

float OrganSynth::getSamples()
{

    return (OrganOne.getSample() + OrganTwo.getSample()) / 2;
}

void OrganSynth::tickAll()
{

    OrganOne.tick(); // zet dit misschien in de synth
    OrganTwo.tick();
}