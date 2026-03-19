#include "onepole.h"

Onepole::Onepole(){

    std::cout << "Onepole::Onepole; a onepole " << std::endl;
}

Onepole::~Onepole(){
    std::cout << "Onepole::~Onepole; no onepole" << std::endl;
}

void Onepole::applyEffect(const float& input, float &output){

    output =  0.7*sample + 0.3*input;
    sample = output;
}
