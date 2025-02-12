#ifndef _INTERPOLL_H_
#define _INTERPOLL_H_
#include <iostream>

class Interpoll {
    public:
	static float nnMap(float value, int low, int high); // return nearest value
	static float linMap(float value, int low, int high);
	// f = ax+b
    private:
};

#endif
