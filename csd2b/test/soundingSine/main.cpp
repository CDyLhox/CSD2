#include <iostream>
#include "customCallback.h"
#include "writeToFile.h"

int main()
{
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource(44100);
    JUCEModule juceModule(audioSource);
    juceModule.init(1, 1);

    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running)
    {
        switch (std::cin.get())
        {
        case 'q':
            running = false;
            break;
        }
    }

    WriteToFile fileWriter("output.csv", true);
    for (int i = 0; i < sampleRate; i++)
    {
        fileWriter.write(std::to_string(sine.getSample()) + "\n");
        sine.tick();
    }

    return 0;
}
