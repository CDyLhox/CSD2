#include "callback.h"
#include "synth.h"

Callback::Callback(float sampleRate)
    : AudioCallback(sampleRate), samplerate(sampleRate)
{
  std::cout << "Hallo CSD'er :)" << std::endl;
}

void Callback::prepare(int rate) // dit is de functie om alles klaar te leggen              DIT IS DE STARTUP
{
  samplerate = (float)rate;

  std::cout << "\nsamplerate: " << samplerate << "\n";

  updatePitch(melody);
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
      outputChannels[channel][sample] *= 0.4f;


      if (frameIndex >= noteDelayFactor * samplerate)
      {
        frameIndex = 0;
        updatePitch(melody);
      }
      else
      {
        frameIndex++;
      }
    }
  }
}

// TODO : move to different file
double Callback::mtof(float mPitch)
{
  return 440.0 * pow(2.0, (mPitch - 69.0f) / 12.0f);
}

void Callback::updatePitch(Melody &melody)
{
  float note = melody.getNote();
  double freq = mtof(note);
  std::cout << "next note: " << note << ", has frequency " << freq
            << std::endl;
  synth.setFrequencies(freq);
  // .setFrequency(freq); // synth.setfrequency
}
