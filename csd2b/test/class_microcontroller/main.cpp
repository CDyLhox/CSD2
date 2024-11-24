#include <iostream>
#include "microcontroller.h"

int main(){
    std::string type;
    std::cout << "this stuff is pretty meta, a microcontroller runs in c" << std::endl;
    std::cout << "what type of microcontroller are you using?" << std::endl;
    std::cin >> type;

    microcontroller aMicrocontroller(type);
    return 0;
}