
#include "eeg.h"
#include <math.h>
#include <stdlib.h>

static float t = 0.0f;


void EEG_Init(void){
	t = 0.0f;
}


void EEG_GenerateSample(int32_t *buffer)
{
    float dt = 1.0f / EEG_SAMPLING_RATE;
    t += dt;

    float signal = sinf(2.0f * M_PI * 10.0f * t)
                 + sinf(2.0f * M_PI * 20.0f * t);

    float noise = ((float)rand() / RAND_MAX - 0.5f);
    noise *= 0.2f;

    signal += noise;

    int32_t value = (int32_t)(signal * 1000000);

    buffer[0] = value;
}

