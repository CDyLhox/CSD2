#ifndef _GITARE_H_
#define _GITARE_H_

#include "stringInstrument.h"

class Gitare : public StringInstrument
{
private:
public:
    Gitare(/* args */);
    ~Gitare();


    void play(int range);
};



#endif