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
    for (int i = 0; i < numChannels; i++){
        for (int q = 0; q < AMOUNT_OF_DELAYS; q++){
            std::cout << "q" << q << std::endl;
            std::cout << "i" << i << std::endl;
            delay[i][q].setBypass(false);
            delay[i][q].setDryWet(0.5);
            delay[i][q].setFeedback(targetParameter);
            delay[i][q].setNumDelaySamples(4000 * q);
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
    float sample1;
    float sample2;

    for (int y = 0u; y < AMOUNT_OF_DELAYS; y++) {
        delay[0][y].setFeedback(targetParameter);
        delay[1][y].setFeedback(targetParameter);
    }
    //std::cout<<targetParameter<<std::endl;
    // NOTE: user input
    for (int channel = 0u; channel < numInputChannels; channel++) {
        for (int i = 0u; i < numFrames; i++) {
            //std::cout << "input" << inputChannels[channel][i] << std::endl;

            allpass[channel][0].processFrame(inputChannels[0][i],sample1);

            for (int u = 1; u < AMOUNT_OF_ALLPASS; u++){
                allpass[channel][u].processFrame(sample1, sample2);
            }
            for (int o = 0; o < AMOUNT_OF_DELAYS - 1; o++ ){
                delay[channel][o].processFrame(sample2, sample1);
            }
            delay[channel][AMOUNT_OF_DELAYS - 1].processFrame(sample1, outputChannels[channel][i]);
            //std::cout << "output" << outputChannels[channel][i] << std::endl;
        }
    }
}
