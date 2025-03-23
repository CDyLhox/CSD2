#include "waveshaper.h"

Waveshaper::Waveshaper()
{ // TODO: init buffer
				std::cout << "WAVESHAPER - i must be :: allocating buffer" << std::endl;
				m_waveTableBuffer = new float[m_bufferSize];
				fillBuffer();
}

Waveshaper::~Waveshaper()
{ // TODO: delete buffer
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
												m_sample = 0.999;
								}
								if (m_sample < -0.999) {
												m_sample = -0.999;
								}
								int i = int(m_index);
								float indexDecimal = m_index - (float)i;
								output = Interpolation::linMap(indexDecimal, m_waveTableBuffer[i], m_waveTableBuffer[i + 1]);

								std::cout << "index" << m_index << "\n";
								std::cout << "indexDecimal" << indexDecimal << std::endl;
								std::cout << "output " << output << std::endl;

								// output = 1 / std::atan(m_slope) * std::atan(input * m_slope); // is reference
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
								// fill wavetable buffer with atan slope
								// based on code by cas huurdeman
								float sample = (float)i / (0.5f * m_bufferSize) - 1.0f;
								m_waveTableBuffer[i] = (1.0f / atan(m_slope)) * atan(m_slope * sample);
 // TODO - bron (prikle)
				}
}
