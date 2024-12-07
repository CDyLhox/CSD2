#include "saw.h"

Saw::Saw(float frequency, float samplerate)
    : Oscillator(frequency, samplerate)
{
    std::cout << "saw::saw - i came ,  \n";
}

Saw::~Saw(){std::cout << "saw::saw - i saw\n";}

void Saw::calculate(){
    sample = (phase * 2.0) - 1.0;
}