#include "organSynth.h"

OrganSynth::OrganSynth()
{
    std::cout << "the organ in my body goes " << "\033[31m" << "'Badoenk badoenk'" << "\033[97m" << std::endl;
}

OrganSynth::~OrganSynth()
{
}

void OrganSynth::setFrequencies(float frequency)
{
    OrganOne.setFrequency(frequency);
    OrganTwo.setFrequency(frequency * 1.51f);
}

float OrganSynth::getAllSamples()
{
    float allSamples = (OrganOne.getSample() + OrganTwo.getSample()) / 2;
    return allSamples;
}

void OrganSynth::tickAll()
{
    OrganOne.tick();
    OrganTwo.tick();
}