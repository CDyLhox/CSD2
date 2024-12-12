#include "square.h"
#include "math.h"

Square::Square(float frequency, float samplerate)
    : frequency(frequency), amplitude(1.0), phase(0), sample(0),
      samplerate(samplerate) {
  std::cout << "Square - a squarewave \n";
}

Square::~Square() { std::cout << "Square - No square wave \n"; }

void Square::getSamplerate(float samplerate) { this->samplerate = samplerate; }

float Square::getSample() { return sample; }

void Square::tick() {
  phase += frequency / samplerate;
  if (phase > 1.0f) {
    phase -= 1.0f;
  }
  if (phase > 0.1f) {
    sample = 1;
  } else if (phase > 0.5f) {
    sample = -1;
  }
}

void Square::setFrequency(float frequency) { this->frequency = frequency; }

float Square::getFrequency() { return frequency; }