
	void prepare(int SAMPLERATE);
	void applyEffect(const float &input, float &output);
	float processFrame(const float &inut, float &output);
	float getSample(){
	return sample;
	}
	void setDryWet(float drywet);

void setDelayTime(int numSamplesDelay)
{ 	// take current writeheadPosition and last numSamplesDelay setting.
	// old numSamplesDelay - new NumsamplesDelay += writeHeadPosition
	writeHeadPosition;
}
void setDelayTime(float miliSecondsDelay) {
	//SAMPLERATE / (miliSecondsDelay/1000) 

}
