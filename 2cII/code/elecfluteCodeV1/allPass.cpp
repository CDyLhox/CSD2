#include "allpass.h"

Allpass::Allpass(){
    std::cout << "Allpass::allpass, an allpass filter" << std::endl;

}

Allpass::~Allpass(){
    
    std::cout << "Allpass::~allpass, nan allpass filter" << std::endl;
}

void Allpass::applyEffect(const float& input, float& output){
    //the program comes from https://thewolfsound.com/allpass-filter/
    //lets try it out why dont we 
    //Figure 2. Block diagram of the first-order allpass filter.
    //std::cout << " allpass::applyeffect input: " << input << std::endl;
    sample1 = buffer.readHead();
    v = input - a * sample1;
    output = a * v + sample1;
    buffer.writeHead(v);
    buffer.tick();
    //sample1 = v;
}
