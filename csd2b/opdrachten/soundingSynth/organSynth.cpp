#include "organSynth.h"

OrganSynth::OrganSynth(/* args */)
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
    OrganTwo.setFrequency(OrganOne.getFrequency() * 1.5);
}

float OrganSynth::getSamples()
{
    return (OrganOne.getSample() + OrganTwo.getSample()) / 2;

    OrganOne.tick(); // zet dit misschien in de synth
    OrganTwo.tick();

}