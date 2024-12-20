#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}



float Melody::getNote()
{
  // wrap index back to the beginning
  if(index >= NUM_NOTES) {
    index = 0;
    
  }
  const auto value = melody[index++];

  // index++ --> use value, then increment
  return value;
}
