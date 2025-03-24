#include "waveshaper.h"

Waveshaper::Waveshaper()
{ //  init buffer
				std::cout << "WAVESHAPER - i must be :: allocating buffer" << std::endl;
				m_waveTableBuffer = new float[m_bufferSize];
				fillBuffer();
}

Waveshaper::~Waveshaper()
{ //  delete buffer
	//
				std::cout << "WaveShaper::~waveshaoer\n"
									<< "Elements of the Buffer were: ";
				for (int i = 0; i < m_bufferSize; i++) {
								std::cout << "\033[31m" << m_waveTableBuffer[i] << "\033[0m" << " ";
				}
				std::cout << m_waveTableBuffer << std::endl;

				delete[] m_waveTableBuffer;
				m_waveTableBuffer = nullptr;
				std::cout << "waveshaper i am no longer" << std::endl;
}

void Waveshaper::applyEffect(const float& input, float& output)
{
				if (m_isBypassed == true) {
								output = input;
				} else {
								// function from prikle page somewhat
								m_sample = input;
								if (m_sample > 0.999) {
												m_sample = 1.0f;
								}
								if (m_sample < -0.999) {
												m_sample = -1.0f;
								}

								m_index = (m_sample + 1.0f) * (m_bufferSize - 1) / 2.0f;

								int i = (int)m_index;

								float indexDecimal = m_index - (float)i;

								if (m_index < 0) {
												m_index = 0;
								} else if (i >= m_bufferSize - 1) {

												i = m_bufferSize - 2;
								}

								output = Interpolation::linMap(indexDecimal, m_waveTableBuffer[i], m_waveTableBuffer[i + 1]);
				}
}

void Waveshaper::setSlope(double slope)
{																										// TODO fix the uhh to make sure to check for ints and if not float rm -rf fr "*/"
				if (slope > 999999999999999 || slope < 1) { // double
								std::cout << "please choose a number between 1 and 999999999999999" << std::endl;
								return;
				}

				m_slope = slope;
				fillBuffer();
}

void Waveshaper::fillBuffer()
{
				for (int i = 0; i < m_bufferSize; i++) {
								float sample = (2.0f * i) / (m_bufferSize - 1) - 1.0f; // Map i to [-1, 1]
								float atanValue = atan(m_slope * sample);

								// Debugging output
								std::cout << "Sample: " << sample << ", atanValue: " << atanValue << std::endl;

								// Scale the output to ensure it stays within [-1, 1]
								m_waveTableBuffer[i] = (1.0f / atan(m_slope)) * atanValue; // Original calculation
																																					 // Optionally scale the output
																																					 // m_waveTableBuffer[i] *= scalingFactor; // Uncomment and set scalingFactor as needed
				}
}
