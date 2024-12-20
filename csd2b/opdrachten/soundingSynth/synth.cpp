#include "synth.h"

Synth::Synth()
{
    std::cout << "synth::synth - Synth i am a SYNTH" << std::endl;
}

Synth::~Synth()
{
    std::cout << "synth::synth - synths i am no more a synth" << std::endl;
}

void Synth::tickAll()
{
}

float Synth::getAllSamples()
{
}

// TODO : move to different file
double Synth::mtof(float mPitch)
{
    return 440.0 * pow(2.0, (mPitch - 69.0f) / 12.0f);
}

void Synth::updatePitch(Melody &melody)
{

    float note = melody.getNote();
    double freq = mtof(note);
    std::cout << "\033[93m" << "next note: " << "\033[97m" << note << "\033[93m" << ", has frequency " << "\033[97m" << freq
              << std::endl;
    setFrequencies(freq);
}
