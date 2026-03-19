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

    reverbs.clear();

    for (int ch = 0; ch < numChannels; ch++)    {
        reverbs.emplace_back(samplerate);
    }

    // zet hier ff je bypass

    waveshaper.setBypass(true);

    waveshaper.setDryWet(1);

    waveshaper.setSlope(0.5);

}

void CustomCallback::process(AudioBuffer buffer)
{

    if (targetParameter != lastParameter) {
        for (int ch = 0; ch < numChannels; ch++)
            reverbs[ch].setDelayFeedback(targetParameter);
        lastParameter = targetParameter;
    }


    auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;
    float sample1 = 0.0f;
    float sample2 = 0.0f;
    // NOTE: user input
    for (int channel = 0u; channel < numInputChannels; channel++) {
        for (int i = 0u; i < numFrames; i++) {
            //std::cout << "input" << inputChannels[channel][i] << std::endl;

            float input = (numInputChannels > 0) ? inputChannels[0][i] : 0.0f;
            //float input = inputChannels[channel][i];
            float output;

            reverbs[channel].applyEffect(input, output);

            outputChannels[channel][i] = output;


            //std::cout << "output" << outputChannels[channel][i] << std::endl;
        }
    }
}
