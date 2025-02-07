#include "synth.h"

Synth::Synth()
{
}

Synth::~Synth()
{
}

void Synth::tickAll()
{
}

float Synth::getAllSamples()
{
    return 0;
}

float Synth::mtof(float mPitch)
{
    return 440.0f * pow(2.0f, (mPitch - 69.0f) / 12.0f);
}

void Synth::updatePitch(Melody &melody)
{
    float note = melody.getNote();
    float freq = mtof(note);
    std::cout << "\033[93m" << "next note: " << "\033[97m" << note << "\033[93m" << ", has frequency " << "\033[97m" << freq
              << std::endl;
    setFrequencies(freq);
}


// a virtual function to handle userparameters for the different synthtypes
int Synth::setExtraParameters(int parameter)
{
    return parameter;
}
