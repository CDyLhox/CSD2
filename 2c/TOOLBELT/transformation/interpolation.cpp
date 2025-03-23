//
// based on code by Semuel Leijten.
//

#include "interpolation.h"

float Interpolation::nnMap(float value, float low, float high)
{
				if (value < 0) {
								std::cout << "nnMap value is lower than 0. clamping to zero" << std::endl;
								value = low;
								return low * (1 - value) + high * value;
				} else if (value > 1) {
								std::cout << "nnMap value is higher than 1. clamping to zero" << std::endl;
								value = high;
								return low * (1 - value) + high * value;
				}

				if (static_cast<int>(value + 0.5f) == 0) {
								return low;
				}
				return high;
}

float Interpolation::linMap(float value, float low, float high)
{
				if (value < 0) {
								std::cout << "linmap value is lower than 0. clamping to zero" << std::endl;
								value = low;
								return low * (1 - value) + high * value;

				} else if (value > 1) {
								std::cout << "linmap value is higher than 1. clamping to zero" << std::endl;
								value = high;
								return low * (1 - value) + high * value;
				}

				return low * (1 - value) + high * value;
}

float Interpolation::mapInRange(float value, float fromLow, float fromHigh, float toLow, float toHigh)
{

				float partial = (value - fromLow) / (fromHigh - fromLow);
				float delta = toHigh - toLow;

				return toLow + delta * partial;
}
