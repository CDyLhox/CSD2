#include "instrument.h"

Instrument::Instrument()
{
    // if (instrumentName == "gitare")
    // {
        
    // }
    // else if (instrumentName == "bass")
    // {
    //     std::cout << "alright play that thing." << std::endl;
    //     Sound = "bong";
    // }
    // else
    // {
    //     Sound = "not a valid input";
    // }
}

Instrument::~Instrument()
{
    std::cout << "i am now a dj" << std::endl;
}

void Instrument::play(){
    std::cout << "iAmInstrument" << std::endl;
}