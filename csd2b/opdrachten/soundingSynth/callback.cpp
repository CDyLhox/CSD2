#include "callback.h"

#include "UIUtility.h"
#include "synth.h"

Callback::Callback(float sampleRate)
    : AudioCallback(sampleRate), samplerate(sampleRate)
{
}

void Callback::prepare(int rate) // dit is de functie om alles klaar te leggen              DIT IS DE STARTUP
{

  UIUtility SynthUI;
  int synthtype = SynthUI.selectSynthesizer();
  std::cout << synthtype << std::endl;
  if (synthtype == 1)
  {
    int amountofsinewaves = SynthUI.setAmountOfSinewaves();
    synth = new Additivesynth; // hier zeggen  welke je wilt hebben toch jeweet
  }
  else{
    synth = new OrganSynth; // hier zeggen  welke je wilt hebben toch jeweet
  }
  samplerate = (float)rate;

  std::cout << "\nsamplerate: " << "\033[97m" << samplerate << "\n";

  synth->updatePitch(melody);
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

    synth->tickAll();
    for (int channel = 0u; channel < numOutputChannels; ++channel)
    {
      outputChannels[channel][sample] = synth->getAllSamples();
      // outputChannels[channel][sample] = organSynth.getAllSamples();

      if (frameIndex >= noteDelayFactor * samplerate)
      {
        frameIndex = 0;
        synth->updatePitch(melody);
      }
      else
      {
        frameIndex++;
      }
    }
  }
}
