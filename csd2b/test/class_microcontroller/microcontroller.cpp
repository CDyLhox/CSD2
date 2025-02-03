#include <iostream> 
#include "microcontroller.h"

microcontroller::microcontroller(){
    std::cout << "yes hello i am a type of microcontroller" << std::endl;
}

microcontroller::microcontroller(std::string type){
    if(type == "yourmom" || type == "jemoeder"){
        std::cout << "\033[31m" << "DONT YOU DARE SPEAK HER NAME" << std::endl;
    }
    else{
    std::cout << "its pretty funny that you told me what type of microcontroller i am and i tell you the same info. im guessing youre using a: " << type << std::endl; 
    }
}
