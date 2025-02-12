// #include "interpoll.h"
#include <iostream>

class Interpoll {
    public:
	// static float nnMap(float value, int low, int high); // return nearest value
	// static float linMap(float value, int low, int high);
	//  f = ax+b
	static float nnMap(float value, int low, int high)
	{
		if (low - value < high - value) {
			return low;
		} else {
			return high;
		}
	}

	static float linMap(float value, int low, int high)
	{
		return low + (high * value - 1);
	}
};

int main()
{
	float value;
	int low;
	int high;
	std::cout << Interpoll::nnMap(14, 2, 12) << std::endl;

	std::cout << "test" << std::endl;
	return 0;
}
