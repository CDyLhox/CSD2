#include <iostream>
#include "instruments.h"

using namespace std;

int main()
{
    cout << "what instrument do you want? (gitare or bass): " << endl;
    string instrumentName;
    cin >> instrumentName;

    Instrument aInstrument(instrumentName);

    aInstrument.play();
    return (0);
}
