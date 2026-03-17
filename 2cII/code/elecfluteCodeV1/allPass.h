#pragma once

#include "effect.h"
#include <iostream>
#include <math.h>
#include "circBuffer.h"

class Allpass : public Effect {
    public:
    Allpass();
    ~Allpass();

    void applyEffect(const float& input, float& output) override;
    private:
    float a = 0.9f;       //   a^1     
    float sample1 = 0.0f; //   z^-1
    float v = 0.0f;       //   v[n-1]
    
    CircBuffer buffer{800, 400}; 

};
