#include "callback.h"

CustomCallback::CustomCallback (float sampleRate)
  : AudioCallback (sampleRate), samplerate (sampleRate) {
  std::cout << "Hallo CSD'er :)" << std::endl;
}

void CustomCallback::prepare (int rate) {
  samplerate = (float) rate;
  sineOsc.setSamplerate (samplerate);
  squareOsc.setSamplerate (samplerate);
  sawOsc.setSamplerate (samplerate);
  std::cout << "\nsamplerate: " << samplerate << "\n";
}

void CustomCallback::process (AudioBuffer buffer) {
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int channel = 0u; channel < numOutputChannels; ++channel) {
    for (int sample = 0u; sample < numFrames; ++sample) {
      // outputChannels[channel][sample] = squareOsc.getSample() + sineOsc.getSample() + sawOsc.getSample();
      outputChannels[channel][sample] = sawOsc.getSample();
      outputChannels[channel][sample] *= 0.4f;
      // squareOsc.tick();
      sawOsc.tick();
      // sineOsc.tick();
    }
  }
}

