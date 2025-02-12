

class Effect{


	bool isBypassed = 1;

	protected:
	void prepare(int SAMPLERATE);
	float processFrame(const float &input, float &output);
	virtual void applyEffect(const float &input, float &output) = 0;
	float getSample();
	void setDryWet(float drywet);

	float drywet = 1;



};
