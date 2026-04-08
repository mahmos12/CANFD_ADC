#ifndef ECG_H
#define ECG_H

#include <stdint.h>

#define ECG_CHANNELS 5
#define ECG_SAMPLING_RATE 1024

void ECG_Init(void);
void ECG_GenerateSample(int16_t *buffer);


#endif
