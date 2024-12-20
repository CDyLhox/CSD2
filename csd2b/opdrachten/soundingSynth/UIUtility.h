#ifndef _UIUTILITY_H_
#define _UIUTILITY_H_

#include <iostream>

class UIUtility
{
private:
    std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
    int numWaveFormOptions = 4;

protected:
    /* data */
public:
    int retrieveUserSelection(std::string selectionOptions[], int numOptions);
    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);
    float retrieveValueInRange(float min, float max);
    UIUtility();
    ~UIUtility();
};

#endif