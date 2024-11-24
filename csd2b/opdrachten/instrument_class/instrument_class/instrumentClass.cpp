#include <iostream>


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
    void play()
    {
        if (Sound == "not a valid input")
        {
            cout << "nosound.." << Sound << endl;
        }
        else
        {
            cout << "im an instrument and im playing music check it out: " << Sound << endl;
        }
    }
};

int main()
{
    cout << "what instrument do you want? (gitare or bass): " << endl;
    string instrumentName;
    cin >> instrumentName;

    Instrument aInstrument(instrumentName);

    aInstrument.play();
    return (0);
}
