#pragma once

#include <iostream>

#define NUM_NOTES 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();

protected:
  // my most spooky song
  float melody[NUM_NOTES] = {64, 57, 61, 55, 52, 57, 55, 52, 50, 48};
  // the index of the current note - readIndex
  int index = 0;
};