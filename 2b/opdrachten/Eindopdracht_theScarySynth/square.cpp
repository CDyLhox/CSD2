#include "square.h"

Square::Square(float frequency, float samplerate)
    : Oscillator(frequency, samplerate)
{
}

Square::~Square()
{
}

void Square::calculate()
{
  if (phase < 0.5f)
  {
    sample = 1.0f;
  }
  else
  {
    sample = -1.0f;
  }
}
