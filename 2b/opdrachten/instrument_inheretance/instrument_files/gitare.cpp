#include "gitare.h"

Gitare::Gitare()
{
    std::cout << "ah yeah nice." << std::endl;
}

Gitare::~Gitare()
{
}

void Gitare::play(int range)
{
    if (range < 400)
    {
        std::cout << "cutoff" << std::endl;
    }
    else
    {

        std::cout << range << std::endl;
    }

    std::cout << Sound << std::endl;
}