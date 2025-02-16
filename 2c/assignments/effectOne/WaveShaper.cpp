#include "waveshaper.h"

Waveshaper::Waveshaper(){
	std::cout << "WAVESHAPER - i must be" << std::endl;
}

Waveshaper::~Waveshaper(){
	std::cout << "waveshaper i am no longer" << std::endl; 
}

void Waveshaper::applyEffect(const float &input, float &output){
	//TODO ADD THE ARCTAN FUNCTION

	std::cout <<"a function : "<< (input) << std::endl;
	std::cout <<"a atan function : "<< 1/std::atan(m_slope)*std::atan(input*m_slope) << std::endl;
	output =  1/std::atan(m_slope)*std::atan(input*m_slope); 

}	
