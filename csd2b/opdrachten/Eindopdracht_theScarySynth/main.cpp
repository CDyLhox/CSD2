#include "audioToFile.h"
#include "callback.h"
#include <iostream>
#include <thread>

#define WRITE_TO_FILE 0

int main(int argc, char **argv)
{
  ScopedMessageThreadEnabler scopedMessageThreadEnabler;
  Callback audioSource(44100);

#if WRITE_TO_FILE
  AudioToFile audioToFile;
  audioToFile.write(audioSource);
#else

  JUCEModule juceModule(audioSource);
  juceModule.init(2, 2);

  std::cout << "Press q + Enter to quit..." << std::endl;
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
    case 'q':
      // this should be in the synth destructor but the synthpointer prohibits me
      std::cout << "ah yes, byebye" << std::endl;
      running = false;
    }
  }
#endif
  // end the program
  return 0;
} // main()