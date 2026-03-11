#pragma once

#include "effect.h"
#include <iostream>
#include <math.h>

class Allpass : public Effect {
    Allpass();
    ~Allpass();

    void applyEffect(const float& input, float& output) override;

};
