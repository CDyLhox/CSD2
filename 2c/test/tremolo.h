// infndef

#include <iostream>

class Tremolo { // a multiplication is cheaper than a devision
    public:
	Tremolo();
	~Tremolo();

	float setModDepth(float depth);
	void processFrame(float input);
	void prepare(float samplerate);
	void setFrequency(float freq);
    private:
	Sine sine;
       	float modDepth;
}
