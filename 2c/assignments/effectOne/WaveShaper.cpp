#include "waveshaper.h"

Waveshaper::Waveshaper()
{
	std::cout << "WAVESHAPER - i must be" << std::endl;
}

Waveshaper::~Waveshaper()
{
	std::cout << "waveshaper i am no longer" << std::endl;
}

void Waveshaper::applyEffect(const float& input, float& output)
{
	if (m_isBypassed == true) {
		output = input;
	} else {
		output = 1 / std::atan(m_slope) * std::atan(input * m_slope); // is reference
	}
}

void Waveshaper::setSlope(long slope)
{//TODO fix the uhh to make sure to check for ints and if not float rm -rf fr "*/"
	if(slope > 999999999999999999 || slope < 1){
	std::cout << "please choose a number between 1 and 999999999999999999" << std::endl;
	}
	m_slope = slope;
}
