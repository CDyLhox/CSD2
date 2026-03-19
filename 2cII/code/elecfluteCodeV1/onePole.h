#pragma once

#include "effect.h"
#include <iostream>

//y[n] = 0.7*y[n-1] + 0.3*x[n]
//
class Onepole : public Effect {
    public:
        Onepole();
        ~Onepole();
        void applyEffect(const float& input, float& output) override;
    private:
        float sample = 0;

};
