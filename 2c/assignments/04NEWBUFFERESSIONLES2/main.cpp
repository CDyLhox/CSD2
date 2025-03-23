#include "circBuffer.h"
#include <audioToFile.h>
#include <iostream>
#include <square.h>
#include <thread>

#define SAMPLERATE 44100

int main(int argc, char** argv)
{
	// set delay to a quarter cycle
	int cycleFrameLength = 80;
	CircBuffer circBuffer(200, cycleFrameLength / 4);

	// init square oscillator based on cycle lengths
	float freq = (float)SAMPLERATE / cycleFrameLength;
	Square square(freq, SAMPLERATE);

	const std::string sourcePath = SOURCE_DIR;
	WriteToFile fileWriter(sourcePath + "/output.csv", true);

	// generate 200 samples
	float squareSample = 0;
	float delaySample = 0;
	for (int i = 0; i < 200; i++) {
		squareSample = square.genNextSample();
		
		circBuffer.writeHead(squareSample);
		circBuffer.tick();

		
		fileWriter.write(std::to_string((squareSample+circBuffer.readHead()) / 2) + "\n");
	}

	std::cout << "\n***** DONE ***** "
		  << "\nWrote the sum of the a sine oscillator and a "
		  << "delayed value to output.csv." << std::endl;

	// end the program
	return 0;

} // main()
