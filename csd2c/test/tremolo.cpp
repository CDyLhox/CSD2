#include "tremolo.h"

Tremolo::Tremolo()
{
}

Tremolo::Tremolo ~()
{
}

float Tremolo::processFrame(float input)
{
}

void Tremolo::setModDepth(float depth)
{
	if (depth >= 0 && depth <= 1) {
		modDepth = depth;
	} else {
		std::cout << "Tremolo::tremolo - incorrect usage of the uhh"
	}
}
