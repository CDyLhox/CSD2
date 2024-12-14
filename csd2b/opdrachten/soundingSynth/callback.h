#ifndef CALLBACK_H
#define CALLBACK_H

#include "audiocomponent.h"
#include "melody.h"
#include "synth.h"
class Callback : public AudioCallback
{
public:
  Callback(float sampleRate);
  void prepare(int rate) override;
  void process(AudioBuffer buffer) override;

  double mtof(float mPitch);
  void updatePitch(Melody &melody);

private:
  float samplerate = 44100;

  double amplitude = 0.25;
  int frameIndex = 0;

  Melody melody;
  Synth synth{44100};

  double noteDelayFactor = 1.0;
};

#endif // CALLBACK_H
