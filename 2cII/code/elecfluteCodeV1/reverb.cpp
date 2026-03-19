#include "reverb.h"

Reverb::Reverb(float sr) : samplerate(sr)
{
    std::cout << "the reverb initialises" << std::endl;


    for (int u = 0; u < AMOUNT_OF_ALLPASS; u++){
        allpass[0][u].setBypass(false);
        allpass[0][u].setDryWet(1);
        allpass[1][u].setBypass(false);
        allpass[1][u].setDryWet(1);
    }

    float minDelay = 0.03f * samplerate;
    float maxDelay = 0.045f * samplerate;
    for (int i = 0; i < numChannels; i++){
        for (int q = 0; q < AMOUNT_OF_DELAYS; q++){
            std::cout << "q" << q << std::endl;
            std::cout << "i" << i << std::endl;
            delay[i][q].setBypass(false);
            delay[i][q].setDryWet(0.5);
            delay[i][q].setFeedback(parameterInit);

            float t = (float)q / (AMOUNT_OF_DELAYS - 1);
            int delaySamples = minDelay + t * (maxDelay - minDelay);

            // theres a dynamic way of doing it or just straight values. values works better in general
            int combDelays[4] = {1491, 1601, 1723, 1867};//{1557, 1617, 1491, 1422};

            delay[i][q].setNumDelaySamples(combDelays[q]);
            // 30ms, 35.5,
            //TODO: set alle delays op een andere hoeveelheid samples
        }
    }
}


Reverb::~Reverb(){
    std::cout << "i am not a reverb anymore" << std::endl;
}
void Reverb::applyEffect(const float& input, float& output)
{
    float combSum = 0.3f;

    for (int c = 0; c < AMOUNT_OF_DELAYS; c++)
    {
        float combOut;
        delay[0][c].processFrame(input, combOut);

        if (c % 2 == 1)
            combOut = -combOut;

        combSum += combOut;
    }

    float ap;
    allpass[0][0].processFrame(combSum, ap);

    for (int p = 1; p < AMOUNT_OF_ALLPASS; p++)
    {
        allpass[0][p].processFrame(ap, ap);
    }

    output = ap;
}

void Reverb::setDelayFeedback(float feedback){
    std::cout << "Reverb::setDelayFeedback(), setting feedback to: " << feedback << std::endl;
    feedback = std::clamp(feedback, 0.0f, 0.95f);
    for (int n = 0; n < numChannels; n++){
        for (int i = 0; i < AMOUNT_OF_DELAYS; i++){
            delay[n][i].setFeedback(feedback);
        }
    }
}
