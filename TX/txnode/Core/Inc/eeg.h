#ifndef EEG_H
#define EEG_H

#include <stdint.h>

#define EEG_CHANNELS 1
#define EEG_SAMPLING_RATE 1024

void EEG_Init(void);
void EEG_GenerateSample(int32_t *buffer); // 24-bit → int32

#endif
