#include "melody.h"

Melody::Melody()
{}

Melody::~Melody()
{}


/*
 * getNote() reads the next note from the 01_melody
 *  and wraps around to the beginning when it reached the end
 *  of the 01_melody
 */
float Melody::getNote()
{
  std::cout << "im here at the melody.cpp" << std::endl;
  // wrap index back to the beginning
  if(index >= NUM_NOTES) {
    index = 0;
    
  }
  std::cout << index << std::endl;
  const auto value = melody[index++];

  // index++ --> use value, then increment
  return value;
}
