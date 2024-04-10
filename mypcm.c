// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <math.h>	// includes sin()
// Add any necessary headers here

// user-defined header files
#include "mypcm.h" // do not modify this file

// put your function prototypes for additional helper functions below:

extern int arr_size;

float analog_signal_generator(asignal signal, int t)
{
	float result;
    result= signal.A * sin(signal.omega * t + signal.sigma);
    return result;
}

void sampler(float *samples, int interval, asignal signal)
{
	for(int i=0;i<=signal.duration;i++){
		samples[i]=analog_signal_generator(signal,i);
	}
}
void quantizer1(float *samples, int *pcmpulses, int levels)
{
	// TODO
}
void quantizer(float *samples, int *pcmpulses, int levels, float A)
{

	for (int i = 0; i < arr_size; i++)
    {
        float normalized_sample = (samples[i] - (-A)) / (A - (-A));
        int quantized_value = floor(normalized_sample * levels);
        pcmpulses[i] = quantized_value;
    } 

}

void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
	int size = arr_size;
	
	for (int i = 0; i < size; i++)
	{
	 	int num = pcmpulses[i];
	 	for (int j = encoderbits - 1; j >= 0; j--)
		{
			dsignal[i * encoderbits + (encoderbits - j - 1)] = (num >> j) & 1;
		}
	}


}