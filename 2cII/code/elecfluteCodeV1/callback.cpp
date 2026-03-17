#include "callback.h"

CustomCallback::CustomCallback(float sampleRate)
    : AudioCallback(sampleRate)
      , samplerate(sampleRate)
{
}

void CustomCallback::prepare(int rate)
{

    samplerate = (float)rate;
    std::cout << "\nsamplerate: " << samplerate << "\n";

    //OSCSERVER INIT
    oscServer.init (serverport);
    oscServer.set_callback ("/parameter", "f");

    oscServer.start();
    std::cout << "OSC Server listening on port: " << serverport << std::endl;



    // zet hier ff je bypass

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
            delay[i][q].setFeedback(targetParameter);

            float t = (float)q / (AMOUNT_OF_DELAYS - 1);
            int delaySamples = minDelay + t * (maxDelay - minDelay);

            // theres a dynamic way of doing it or just straight values. values works better in general
            int combDelays[4] = {1557, 1617, 1491, 1422};

            delay[i][q].setNumDelaySamples(combDelays[q]);
            // 30ms, 35.5,
            //TODO: set alle delays op een andere hoeveelheid samples
        }
    }
    waveshaper.setBypass(true);

    waveshaper.setDryWet(1);

    waveshaper.setSlope(0.5);

}

void CustomCallback::process(AudioBuffer buffer)
{
    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float sample1 = 0.0f;
    float sample2 = 0.0f;

    for (int y = 0u; y < AMOUNT_OF_DELAYS; y++) {
        delay[0][y].setFeedback(targetParameter);
        delay[1][y].setFeedback(targetParameter);
    }
    //std::cout<<targetParameter<<std::endl;
    // NOTE: user input
    for (int channel = 0u; channel < numInputChannels; channel++) {
        for (int i = 0u; i < numFrames; i++) {
            //std::cout << "input" << inputChannels[channel][i] << std::endl;

            float input = (numInputChannels > 0) ? inputChannels[0][i] : 0.0f;

            float combSum = 0.0f;

            // comb filter
            for (int c = 0; c < AMOUNT_OF_DELAYS; c++)
            {
                float combOut;
                delay[channel][c].processFrame(input, combOut);

                if (c % 2 == 1)
                    combOut = -combOut;

                combSum += combOut;
            }

            float ap1;
            allpass[channel][0].processFrame(combSum, ap1);

            // the rest of the allpassess 
            float ap2;
            for (int p = 1; p < AMOUNT_OF_ALLPASS; p++){
            allpass[channel][p].processFrame(ap1, ap2);
            }
            outputChannels[channel][i] = ap2;


            //std::cout << "output" << outputChannels[channel][i] << std::endl;
        }
    }
}
