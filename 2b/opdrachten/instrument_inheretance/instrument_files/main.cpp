#include <iostream>
#include "instrument.h"
#include "gitare.h"



int main()
{
    std::cout << "what instrument do you want? (gitare or bass): " << endl;
    std::string instrumentName;
    std::cin >> instrumentName;
    
    int range;

    Gitare agitaar;
    std::cout << "note (in hrz) being played " << std::endl;
    std::cin >> range;
    agitaar.play(range);




    return (0);
}
