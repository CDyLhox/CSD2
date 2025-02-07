#include "UIUtility.h"

UIUtility::UIUtility()
{
}

UIUtility::~UIUtility()
{
}

std::string UIUtility::retrieveUserInput(std::string selectionOptions[], int numOptions)
{
    // show user the allowed options
    std::cout << "\033[93m" << "Choose your synth. You can choose from: ";
    for (int i = 0; i < numOptions - 1; i++)
    {
        std::cout << "\033[97m" << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    std::cout << selectionOptions[numOptions - 1] << "\033[93m" << "." << "\033[97m" << std::endl;
    // retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}

int UIUtility::retrieveUserSelection(std::string selectionOptions[], int numOptions)
{
    std::string selection = "";
    while (true)
    {
        // let user choose from the allowed options
        selection = retrieveUserInput(selectionOptions, numOptions);

        // check if the selection is among the available option
        for (int i = 0; i < numOptions; ++i)
        {
            if (selection == selectionOptions[i])
            {
                return i;
            }
        }
        // if we end up here, this means the selection is not correct,
        // so log a message to user to try again
        std::cout << "\033[31m" << "nah uh, Maybe check your spelling? " << std::endl;
    } // while
    return -1; // should never be reached
}

float UIUtility::retrieveValueInRange(float min, float max)
{
    std::string input;
    float value = 0;
    bool notInRange = true;

    while (notInRange)
    {
        std::cout << "\033[93m" << "we will now walk the path of the additive synthesizer. " << std::endl;

        std::cout << "you have a choice to make, either listen to the \n"
                  << "\033[97m" << "saw wave \n"
                  << "\033[97m" << "the creeping BWAM\n"
                  << "\033[97m" << "or the " << "\033[97m" << "Low Growl" << std::endl;

        std::cout << "\033[93m" << "now enter a value between " << "\033[97m" << min << "\033[93m" << " and "
                  << "\033[97m"
                  << max << "\033[97m"
                  << std::endl;
        // first capture input in input string
        std::cin >> input;
        // validate if input string can be transformed into a float
        try
        {
            value = std::stof(input);
            // validate range
            if (value >= min && value <= max)
            {
                notInRange = false;
            }
            else
            {
                // value not in range
                std::cout << "out of range, try again." << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            // no float as input
            std::cout << "Invalid input, expecting a number."
                      << std::endl;
        }
    } // while not in range

    return value;
} // retrieveValueInRange()

int UIUtility::selectSynthesizer()
{
    std::cout << "\033[93m" << "hello hi hello hi" << std::endl;

    int waveTypeSelection = retrieveUserSelection(waveFormOptions, numWaveFormOptions);

    // use the selected option to show the corresponding text
    std::cout << "\033[93m" << "You selected: " << "\033[97m" << waveFormOptions[waveTypeSelection] << std::endl;

    return waveTypeSelection;
}

//ask the user for extra parameter information if necessary
int UIUtility::selectExtraParameter()
{
    int value = retrieveValueInRange(1, 3);
    std::cout << "\033[93m" << "You chose the following: " << "\033[97m" << std::endl;

    switch (value)
    {
    case 1:
        std::cout << "SAW WAVE SELECTED" << std::endl;
        break;
    case 2:
        std::cout << "CRITTERING CRATTING CREEPY BWAM" << std::endl;
        break;
    case 3:
        std::cout << "UEEUEHEGHLL" << std::endl;
        break;

    default:
        std::cout << "something went horribly wrong!" << std::endl;
        break;
    }
    std::cout << "\033[93m";
    return value;
}