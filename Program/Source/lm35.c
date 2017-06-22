#include "lm35.h"

extern int8u lcdptr;

float readtemp(int8u disp)
{
	volatile float temp;
	char tempstr[10];
	
	temp = (TEMP_CONST * adcget(0));
	
	if (disp) {
		ftoa(temp, tempstr, 1);
		lcdptr = disp;
		lcdws("    ");
		lcdptr = disp;
		lcdws(tempstr);
	}
	
	return temp;
}