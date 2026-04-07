#include "reverb.h"

Reverb::Reverb(float sr) : samplerate(sr)
{
    std::cout << "the reverb initialises" << std::endl;

    onepole.setBypass(false);


    for (int i = 0; i < AMOUNT_OF_ALLPASS; i++) {
        allpass[i].setBypass(false);
        allpass[i].setDryWet(1.0f);
    }
    int combDelays[4] = {1491, 1601, 1723, 1867};
    for (int i = 0; i < AMOUNT_OF_DELAYS; i++) {
        delay[i].setBypass(false);
        delay[i].setDryWet(1.0f);
        delay[i].setFeedback(0.5f);
        delay[i].setNumDelaySamples(combDelays[i]);
    }


    // theres a dynamic way of doing it or just straight values. values works better in general
    //int combDelays[4] = {1491, 1601, 1723, 1867};//{1557, 1617, 1491, 1422};

    //TODO: set alle delays op een andere hoeveelheid samples
}


Reverb::~Reverb(){
    std::cout << "i am not a reverb anymore" << std::endl;
}
void Reverb::applyEffect(const float& input, float& output)
{
    float in = freeze ? 0.0f : input;
    float combSum = 0.0f;

    for (int i = 0; i < AMOUNT_OF_DELAYS; i++)
    {
        float y;
        delay[i].processFrame(in, y);

        //y *= 0.25f;
    
        // flip the polarity of each combfilter 
        if (i & 1) y = -y;

        combSum += y;
    }

    combSum /= AMOUNT_OF_DELAYS;


    float ap = combSum;

    for (int i = 0; i < AMOUNT_OF_ALLPASS; i++)
    {
        allpass[i].processFrame(ap, ap);

        if (!std::isfinite(ap)) ap = 0.0f;
    }

    ap *= 0.9f;
    onepole.processFrame(ap, ap);
    output = std::clamp(ap, -1.0f, 1.0f);
}

void Reverb::setDelayFeedback(float feedback){
    //  std::cout << "Reverb::setDelayFeedback(), setting feedback to: " << feedback << std::endl;
    currentFeedback = std::clamp(feedback, 0.0f, 0.99f);

    /*if(currentFeedback > 0.61){
      std::cout << "ok time to freeze" << std::endl;
      freeze = true;
      }
      else{*/

    for (int i = 0; i < AMOUNT_OF_DELAYS; i++) {
        delay[i].setFeedback(currentFeedback);
    }
}

void Reverb::setFreeze(bool state){
    std::cout << "ok we frozen now" << std::endl;
    freeze = state;

    float fb = freeze ? 0.999f : currentFeedback;

    for (int i = 0; i < AMOUNT_OF_DELAYS; i++)
        delay[i].setFeedback(fb);
}
