
#include "ecg.h"
#include <math.h>

static float t = 0.0f;

void ECG_Init(void)
{
    t = 0.0f;
}

void ECG_GenerateSample(int16_t *buffer)
{
    float dt = 1.0f / ECG_SAMPLING_RATE;

    t += dt;

    float phase = fmodf(t, 1.0f);

    float signal = 0.0f;

    if (phase < 0.1f)
    {
        signal = 0.1f;
    }
    else if (phase < 0.12f)
    {
        signal = 1.0f;
    }
    else
    {
        signal = 0.0f;
    }

    int16_t value = (int16_t)(signal * 20000);

    for (int i = 0; i < ECG_CHANNELS; i++)
    {
        buffer[i] = value;
    }
}
