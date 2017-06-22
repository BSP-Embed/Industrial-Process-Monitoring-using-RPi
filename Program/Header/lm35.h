#ifndef LM35_H
#define LM35_H

#include "includes.h"

#define ADC_STEP_SIZE		(2.56 / 1024)
#define ADC_TEMP_CO			(0.01)			/* 10mv per degree celcius */
#define TEMP_CONST			(ADC_STEP_SIZE / ADC_TEMP_CO)	

float readtemp(int8u disp);

#endif