#include "applicationController.h"

ApplicationController::ApplicationController(/* args */)
{
}

ApplicationController::~ApplicationController()
{
}

void ApplicationController::bootSynthesizer()
{
    std::cout << "\033[93m" << "hello hi hello hi" << std::endl;
    std::string waveFormOptions[4] = {"organSynth", "Additivesaw", "poop", "peepee"};
    int numWaveFormOptions = 4;

    int waveTypeSelection = SynthUI.retrieveUserSelection(waveFormOptions, numWaveFormOptions);

    // use the selected option to show the corresponding text
    std::cout << "\033[93m" << "You selected: " << "\033[97m" << waveFormOptions[waveTypeSelection] << std::endl;

    float value = SynthUI.retrieveValueInRange(20, 20499);
    std::cout << "You chose the following value: " << "\033[97m" << value << "\033[93m" << std::endl;
}