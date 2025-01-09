#ifndef _STRINGINSTRUMENTS_H_
#define _STRINGINSTRUMENTS_H_

#include "instrument.h"

class StringInstrument : public Instrument
{
private:
public:
    std::string Sound = "pling";

    StringInstrument();
    ~StringInstrument();
};

#endif