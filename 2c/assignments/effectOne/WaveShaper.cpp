#include "waveshaper.h"

Waveshaper::Waveshaper(){
	std::cout << "WAVESHAPER - i must be" << std::endl;
}

Waveshaper::~Waveshaper(){
	std::cout << "waveshaper i am no longer" << std::endl; 
}

void Waveshaper::applyEffect(const float &input, float &output){
	output =  1/std::atan(m_slope)*std::atan(input*m_slope); //is reference
}

void Waveshaper::setSlope(long slope){
	//TODO ADD VALIDATION
	m_slope = slope;
}
