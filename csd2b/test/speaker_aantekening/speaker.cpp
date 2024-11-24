#include <iostream>

class Speaker {
    public:
    Speaker();
}

Speaker::Speaker(){
    
}


class Tweeter{
    public: 
    Tweeter(float diam);

    float diameter;
    float conePosition;
}

Tweeter::Tweeter(float diam){
    // in cm
    diameter = diam;
    conePosition = 0f; // .number with an f --> indicate its a float
}

//todo - a woofer

int main(){
    Tweeter aTweeter(2.4);

}