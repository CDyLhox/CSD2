//
// Created by Dean on 02/12/2023.
//

#include <audiocomponent.h>
#include <iostream>
#include <saw.h>
#include <sine.h>

struct CustomCallback : AudioCallback {
	explicit CustomCallback(float sampleRate)
	    : AudioCallback(sampleRate)
	{
	}

	~CustomCallback() override
	{
	}

	void prepare(int sampleRate) override
	{
	}

	// OPDRACHT: Maak twee output signalen die verschillen
	// bijv: Links zaagtand, Recht blokgolf
	// bijv: Links Waveshaper, Rechts Delay
	// go nuts
	void process(AudioBuffer buffer) override
	{
		auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

			for (int sample = 0u; sample < numFrames; ++sample) {

				outputChannels[1][sample] = sine.genNextSample();
				outputChannels[0][sample] = saw.genNextSample();

	//			outputChannels[channel][sample] = inputChannels[channel][sample];
			}
	}

    private:
	Sine sine { 440 , 44100};
	Saw saw {550, 44100};
};

int main()
{
	ScopedMessageThreadEnabler scopedMessageThreadEnabler;
	CustomCallback audioSource(44100);
	JUCEModule juceModule(audioSource);
	juceModule.init(2, 2); // Belangrijk dat je hier 2 van maakt

	std::cout << "Press q Enter to quit..." << std::endl;
	bool running = true;
	while (running) {
		switch (std::cin.get()) {
		case 'q':
			running = false;
			break;
		}
	}

	return 0;
}
