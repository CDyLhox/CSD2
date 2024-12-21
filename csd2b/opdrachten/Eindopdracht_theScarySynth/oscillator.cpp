#include "oscillator.h"
#include "math.h"

Oscillator::Oscillator() : frequency(200), amplitude(1.0), phase(0), sample(0), samplerate(44100)
{
  std::cout << "default constructor for the oscillator class" << std::endl;
}

Oscillator::Oscillator(float frequency, float samplerate)
    : frequency(frequency),
      amplitude(1.0),
      phase(0),
      sample(0),
      samplerate(samplerate)
{
}

Oscillator::~Oscillator()
{
}

void Oscillator::setSamplerate(float samplerate)
{
  this->samplerate = samplerate;
}

float Oscillator::getSample() { return sample; }

void Oscillator::tick()
{
  phase += frequency / samplerate;
  // wrap the phase to interval [0, 1]
  if (phase > 1)
    phase -= 1.0;
  calculate();
  sample *= amplitude;
}

// getters and setters
void Oscillator::setFrequency(float frequency)
{
  if (frequency > 20.0f && frequency < 22000.0f)
  {
    this->frequency = frequency;
  }
  else
  {
    std::cout << "i dont think so" << std::endl;
    this->frequency = 440.0f;
  }
}

void Oscillator::setAmplitude(float amplitude)
{
  if (amplitude < 2.0f)
  {
    this->amplitude = amplitude;
  }
  else
  {
    std::cout << "i dont think so" << std::endl;
    this-> amplitude = 1.0f;
  }
}

float Oscillator::getFrequency() { return frequency; }
