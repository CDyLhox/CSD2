#include "applicationController.h"

ApplicationController::ApplicationController(/* args */)
{
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::bootSynthesizer()
{
    std::cout << "hello hi hello hi" << std::endl;
    std::string waveFormOptions[4] = {"organSynth", "Additivesaw", "poop", "peepee"};
    int numWaveFormOptions = 4;

    int waveTypeSelection = SynthUI.retrieveUserSelection(waveFormOptions, numWaveFormOptions);

    // use the selected option to show the corresponding text
    std::cout << "You selected: " << waveFormOptions[waveTypeSelection] << std::endl;

    float value = SynthUI.retrieveValueInRange(20, 20499);
    std::cout << "You chose the following value: " << value << std::endl;
}