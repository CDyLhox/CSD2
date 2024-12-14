#include "organSynth.h"

OrganSynth::OrganSynth(/* args */)
{
    std::cout << "organsynth::organsynth - i think therefore i am an organsynth" << std::endl;
}

OrganSynth::~OrganSynth()
{
    std::cout << "organsynth::organsynth - i am no more organsynth than you are" << std::endl;
}

void OrganSynth::setFrequencies()
{
    OrganOne.setFrequency(220);
    OrganTwo.setFrequency(OrganOne.getFrequency() * 1.5);
}