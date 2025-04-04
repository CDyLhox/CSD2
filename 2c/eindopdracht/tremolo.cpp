#include "tremolo.h"
#include "saw.h"
#include "sine.h"
#include "square.h"
#include <iostream>

// based on code from Ciska Vriezenga

Tremolo::Tremolo(float modFreq, float modDepth,
		WaveformType waveformType, float samplerate)
		: Effect()
		, m_modDepth(modDepth)
{
				// instantiate the oscillator, depending on the passed waveform type
				switch (waveformType) {
				case WaveformType::SINE: {
								m_osc = new Sine(modFreq, samplerate);
								break;
				}
				case WaveformType::SAW: {
								m_osc = new Saw(modFreq, samplerate);
								break;
				}
				case WaveformType::SQUARE: {
								m_osc = new Square(modFreq, samplerate);
								break;
				}
				default:
								throw "Tremelo::Tremelo - incorrect waveformType.";
								break;
				}
}

Tremolo::~Tremolo()
{
				delete m_osc;
				m_osc = nullptr;
}

void Tremolo::prepare(float samplerate)
{
				m_osc->prepare(samplerate);
}

void Tremolo::applyEffect(const float& input, float& output)
{

				// transform sine in range [-1, 1] to range [0, 1]
				m_modSignal = m_osc->genNextSample() * 0.5 + 0.5;
				// apply modDepth
				m_modSignal *= m_modDepth;
				m_modSignal += 1.0 - m_modDepth;
				// apply modulation signal to input and return result
				// invert rmsSignal -- loud is slow trem, quiet is fast trem --- plus also 0.1 so the safetycheck of the setModFreq is okay
				m_rmsSignal = 1.1 - rms.trackSignal(input);
				output = input * m_modSignal;
				// set the modfreq to the rms signal times 2
				setModFreq(m_rmsSignal * m_rmsModFreqAmplifier); // so that the rms signal doesnt get lower than 0.1
}

void Tremolo::setModFreq(float modFreq)
{ // clamp modfreqs
				if (modFreq >= m_modFreqMin) {
								m_osc->setFrequency(m_modFreqMin);
				} else if (modFreq <= m_modFreqMax) {
								m_osc->setFrequency(m_modFreqMax);
				} else {
								m_osc->setFrequency(modFreq);
				}
}
