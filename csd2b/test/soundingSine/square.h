#ifndef _SQUARE_H_
#define _SQUARE_H_
#include <iostream>
#include <cmath>

class Square
{
public:
    Square(float frequency, float samplerate = 44100);
    ~Square();
    void getSamplerate(float samplerate);

    float getSample(); // get current sample

    void tick(); // set next sample

    void setFrequency(float frequency);
    float getFrequency();

private:
    const float pi = acos(-1);
    float frequency;
    float amplitude;
    float phase;

    float sample;
    float samplerate;
};

#endif