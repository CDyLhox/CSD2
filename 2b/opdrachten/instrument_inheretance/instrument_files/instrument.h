#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>

class Instrument
{
private:
public:
    Instrument();
    ~Instrument();
    std::string Sound;
    virtual void play();
};

#endif