#include <iostream>
// #include "instrument_class.cpp"

using namespace std;
class Instrument
{
public:

    string Sound;
    Instrument(string instrumentName)
    {
        if (instrumentName == "gitare")
        {
            cout << "ah yeah nice." << endl;
            Sound = "pling";
        }
        else if (instrumentName == "bass")
        {
            cout << "alright play that thing." << endl;
            Sound = "bong";
        }
        else
        {
            Sound = "not a valid input";
        }
    }
    void play();

};