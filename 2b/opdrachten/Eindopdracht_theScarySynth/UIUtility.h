#ifndef _UIUTILITY_H_
#define _UIUTILITY_H_

#include <iostream>

class UIUtility
{
private:
    std::string waveFormOptions[2] = {"organSynth", "Additivesynth"};
    int numWaveFormOptions = 2;
protected:
public:
    //Ciska's code:
    int retrieveUserSelection(std::string selectionOptions[], int numOptions);

    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

    float retrieveValueInRange(float min, float max);

    UIUtility();
    ~UIUtility();

    int selectSynthesizer();
    int selectExtraParameter();

    
};

#endif