#include <iostream>
#include "realbook.h"

int main(){
    int pagenumber;
    std::cout << "i am the main function also i would like to ask which page you want to read" << std::endl;
    std::cin >> pagenumber;
    
    realbook aRealbook(pagenumber);
    return 0;
}