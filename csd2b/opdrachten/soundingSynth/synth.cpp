#include "synth.h"

Synth::Synth(float samplerate)
{
    sineOsc.setSamplerate(samplerate);
    squareOsc.setSamplerate(samplerate);
    sawOsc.setSamplerate(samplerate);
    std::cout << "synth::synth - Synth i am a SYNTH" << std::endl;
}

Synth::~Synth()
{
    std::cout << "synth::synth - synths i am no more a synth" << std::endl;
}

void Synth::tickAll()
{
    Organsynth.tickAll(); // ciska wat vind jij?
    AdditiveSynth.tickAll();
}

float Synth::getAllSamples()
{
    float samples = AdditiveSynth.getSamples();
    return samples;
}

void Synth::setFrequencies(float freq)
{
    Organsynth.setFrequencies(freq);
    AdditiveSynth.setFrequencies(freq);
    AdditiveSynth.setAmplitudes();
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
