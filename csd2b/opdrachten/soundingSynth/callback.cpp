#include "callback.h"

CustomCallback::CustomCallback(float sampleRate)
    : AudioCallback(sampleRate), samplerate(sampleRate)
{
  std::cout << "Hallo CSD'er :)" << std::endl;
}

void CustomCallback::prepare(int rate)
{
  samplerate = (float)rate;
  sineOsc.setSamplerate(samplerate);
  squareOsc.setSamplerate(samplerate);
  bsquareOsc.setSamplerate(samplerate);
  bsquareOsc.setFrequency(squareOsc.getFrequency() * 1.5 + 1.0);
  sawOsc.setSamplerate(samplerate);
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process(AudioBuffer buffer)
{
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel)
  {
    for (int sample = 0u; sample < numFrames; ++sample)
    {
      // outputChannels[channel][sample] = squareOsc.getSample() + sineOsc.getSample() + sawOsc.getSample();
      outputChannels[channel][sample] = bsquareOsc.getSample() + squareOsc.getSample();
      outputChannels[channel][sample] *= 0.4f;
      squareOsc.tick();
      bsquareOsc.tick();
      // sawOsc.tick();
      // sineOsc.tick();
    }
  }
}
