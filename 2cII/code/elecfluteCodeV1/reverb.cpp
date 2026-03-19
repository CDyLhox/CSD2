#include "reverb.h"

Reverb::Reverb(float sr) : samplerate(sr)
{
    std::cout << "the reverb initialises" << std::endl;

    onepole.setBypass(true);

    for (int u = 0; u < AMOUNT_OF_ALLPASS; u++){
        allpass[u].setBypass(false);
        allpass[u].setDryWet(1);
        allpass[u].setBypass(false);
        allpass[u].setDryWet(1);
    }

    float minDelay = 0.03f * samplerate;
    float maxDelay = 0.045f * samplerate;
    for (int q = 0; q < AMOUNT_OF_DELAYS; q++){
        std::cout << "q" << q << std::endl;
        delay[q].setBypass(false);
        delay[q].setDryWet(0.5);
        delay[q].setFeedback(parameterInit);

        float t = (float)q / (AMOUNT_OF_DELAYS - 1);
        int delaySamples = minDelay + t * (maxDelay - minDelay);

        // theres a dynamic way of doing it or just straight values. values works better in general
        int combDelays[4] = {1491, 1601, 1723, 1867};//{1557, 1617, 1491, 1422};

        delay[q].setNumDelaySamples(combDelays[q]);
        // 30ms, 35.5,
        //TODO: set alle delays op een andere hoeveelheid samples
    }
}


Reverb::~Reverb(){
    std::cout << "i am not a reverb anymore" << std::endl;
}
void Reverb::applyEffect(const float& input, float& output)
{
    float in = freeze ? 0.0f : input;
    float combSum = 0.0f;

    for (int c = 0; c < AMOUNT_OF_DELAYS; c++)
    {
        float combOut;
        delay[c].processFrame(in, combOut);
        onepole.processFrame(combOut, combOut);

        combOut *= 0.5;
        if (c % 2 == 1)
            combOut = -combOut;

        combSum += combOut;
    }

    combSum *= (0.6f / AMOUNT_OF_DELAYS);
    //
    float ap;
    allpass[0].processFrame(combSum, ap);

    for (int p = 1; p < AMOUNT_OF_ALLPASS; p++)
    {
        allpass[p].processFrame(ap, ap);
    }


    output = ap;
}

void Reverb::setDelayFeedback(float feedback){
  //  std::cout << "Reverb::setDelayFeedback(), setting feedback to: " << feedback << std::endl;
    currentFeedback = std::clamp(feedback, 0.0f, 0.95f);

    /*if(currentFeedback > 0.61){
        std::cout << "ok time to freeze" << std::endl;
        freeze = true;
    }
    else{*/
    for (int i = 0; i < AMOUNT_OF_DELAYS; i++){
        delay[i].setFeedback(currentFeedback);
    //}
    }
}

void Reverb::setFreeze(bool state){
    std::cout << "ok we frozen now" << std::endl;
    freeze = state;

    float fb = freeze ? 0.999f : currentFeedback;

    for (int i = 0; i < AMOUNT_OF_DELAYS; i++)
        delay[i].setFeedback(fb);
}
