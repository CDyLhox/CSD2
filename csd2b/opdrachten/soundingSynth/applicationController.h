#ifndef _APPLICATIONCONTROLLER_H_
#define _APPLICATIONCONTROLLER_H_

#include <iostream>
#include "UIUtility.h"

class ApplicationController
{
private:
    /* data */
    UIUtility SynthUI;
public:
    ApplicationController(/* args */);
    ~ApplicationController();

    void bootSynthesizer();
};

#endif