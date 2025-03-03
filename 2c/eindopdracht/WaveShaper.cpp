#include "waveshaper.h"

Waveshaper::Waveshaper()
{//TODO: init buffer
	std::cout << "WAVESHAPER - i must be :: allocating buffer" << std::endl;
	m_waveTableBuffer = new float[4086];

}

Waveshaper::~Waveshaper()
{//TODO: delete buffer
	std::cout << "waveshaper i am no longer" << std::endl;
}

void Waveshaper::applyEffect(const float& input, float& output)
{
	if (m_isBypassed == true) {
		output = input;
	} else {
		//function from prikle page somewhat
		float index = (input + 1.0) * 2048;

		int i = int(index);
		float indexDecimal = index - (float)i;
		output = Interpolation::linMap(indexDecimal, m_waveTableBuffer[i], m_waveTableBuffer[i + 1]);

		//output = 1 / std::atan(m_slope) * std::atan(input * m_slope); // is reference
	}
}

void Waveshaper::setSlope(double slope)
{//TODO fix the uhh to make sure to check for ints and if not float rm -rf fr "*/"
	if(slope > 999999999999999 || slope < 1){//double 
	std::cout << "please choose a number between 1 and 999999999999999" << std::endl;
	}
	m_slope = slope;
}
