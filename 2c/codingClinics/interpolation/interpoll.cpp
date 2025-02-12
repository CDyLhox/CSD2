#include "interpoll.h"

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
