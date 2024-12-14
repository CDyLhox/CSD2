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

float OrganSynth::getSamples()
{
    // (OrganOne.getSample() + OrganTwo.getFrequency()) / 2;
    OrganOne.tick();
    OrganTwo.tick();

    std::cout << "organone" << OrganOne.getSample() << std::endl;
    std::cout << "organtwo" << OrganTwo.getSample() << std::endl;
}