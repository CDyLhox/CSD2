#include <iostream>
#include <sine.h>
// based on code by Cas Huurdeman

int main()
{

				Sine asine ( 550 );
				std::cout << "the main function" << std::endl;

				int bufferSize = 4000;

				float* buffer;
				buffer = new float[bufferSize];

				for(int i = 0; i < bufferSize; i++){
				buffer[i] = asine.genNextSample();	
				}

				float bufferSum = 0.0;
				for(int i = 0; i < bufferSize; i++){
				bufferSum += buffer[i]*buffer[i];
				}
				float RMSSignal = sqrt(bufferSum/bufferSize);
}
