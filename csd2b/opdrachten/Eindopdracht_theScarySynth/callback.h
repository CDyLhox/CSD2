#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "melody.h"
#include "synth.h"

#include "additiveSynth.h"
#include "organSynth.h"
class Callback : public AudioCallback
{
public:
  Callback(float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;


private:
  float samplerate = 44100;

  double amplitude = 0.25;
  int frameIndex = 0;

  Melody melody;
  Synth* synth;

  double noteDelayFactor = 0.8;
};

#endif // CALLBACK_H
