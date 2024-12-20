#include "callback.h"

#include "applicationController.h"
#include "synth.h"

#include "additiveSynth.h"
#include "organSynth.h"

Callback::Callback(float sampleRate)
    : AudioCallback(sampleRate), samplerate(sampleRate)
{
}

void Callback::prepare(int rate) // dit is de functie om alles klaar te leggen              DIT IS DE STARTUP
{
  ApplicationController AplController;
  AplController.bootSynthesizer();

  samplerate = (float)rate;

  std::cout << "\nsamplerate: " << "\033[97m" << samplerate << "\n";

  synth.updatePitch(melody);
}

void Callback::process(AudioBuffer buffer)
{
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int sample = 0u; sample < numFrames; ++sample)
  {
    synth.tickAll();
    for (int channel = 0u; channel < numOutputChannels; ++channel)
    {
      outputChannels[channel][sample] = synth.getAllSamples();

      if (frameIndex >= noteDelayFactor * samplerate)
      {
        frameIndex = 0;
        synth.updatePitch(melody);
      }
      else
      {
        frameIndex++;
      }
    }
  }
}
