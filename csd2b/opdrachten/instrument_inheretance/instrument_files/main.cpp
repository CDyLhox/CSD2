#include <iostream>
#include "instrument.h"
#include "gitare.h"

using namespace std;

int main()
{
    cout << "what instrument do you want? (gitare or bass): " << endl;
    std::string instrumentName;
    cin >> instrumentName;

    Gitare agitaar;
    agitaar.play();




    return (0);
}
