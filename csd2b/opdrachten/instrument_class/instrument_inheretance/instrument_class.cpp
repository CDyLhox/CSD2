#include <iostream>
#include "instruments.h"
using namespace std;





void Instrument::play()
    {
        if (Sound == "not a valid input")
        {
            cout << "nosound.." << Sound << endl;
        }
        else
        {
            cout << "im an instrument and im playing music check it out: " << Sound << endl;
        }
    };