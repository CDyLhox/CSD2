#include <iostream>
#include "realbook.h"

realbook::realbook()
{
    std::cout << "i am a closed realbook containing text" << std::endl;
}

realbook::realbook(int pagenum)
{
    std::cout << "am an open realbook containing text you are reading pagenumber: " << pagenum << std::endl;
    std::cout << "i am turning the page" << std::endl;
    pagenumber += 1;
}