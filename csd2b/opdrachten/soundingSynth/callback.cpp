#include "callback.h"
#include "synth.h"

#include "additiveSynth.h"
#include "organSynth.h"


Callback::Callback(float sampleRate)
    : AudioCallback(sampleRate), samplerate(sampleRate)
{
  std::cout << "Hallo CSD'er :)" << std::endl;
}

void Callback::prepare(int rate) // dit is de functie om alles klaar te leggen              DIT IS DE STARTUP
{
  samplerate = (float)rate;
  // update synth amplitudes

  std::cout << "\nsamplerate: " << samplerate << "\n";

  synth.updatePitch(melody);
}

void Callback::process(AudioBuffer buffer)
{
  auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

  for (int sample = 0u; sample < numFrames; ++sample) // zet de for  channel boven de sample one en de tick buiten de channel one
  {
    synth.tickAll();
    for (int channel = 0u; channel < numOutputChannels; ++channel)
    {
      // outputChannels[channel][sample] = squareOsc.getSample() + sineOsc.getSample() + sawOsc.getSample();
      // outputChannels[channel][sample] = bsquareOsc.getSample() + squareOsc.getSample();
      
      outputChannels[channel][sample] = synth.getAllSamples();
      // outputChannels[channel][sample] = synth.getAllSamples();


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


