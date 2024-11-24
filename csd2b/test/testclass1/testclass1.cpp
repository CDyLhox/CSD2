#include <iostream>

// a class of bookcases which contain books holding some text;

int main(){
    std::cout << "the main function" << std::endl;

    return 0;
}

void book(){
    std::string abook = "i am a book containing text";
}

class bookCase{
    public:
    bookCase();
    void bookCase::book(); // book function initializer

    std::string sometext = "lorum itsum";

    void bookCase::book(std::string sometext);

    std::string abook;

};

bookCase::bookCase(){
    
}


