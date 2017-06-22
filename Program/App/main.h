#ifndef MAIN_H
#define MAIN_H

#include "includes.h"

#define HIGH_THRESHOLD		35
#define DELTA				5
#define HIGH_LEVEL			80
#define LOW_LEVEL			20


struct  {
	volatile int8u Meas:1;
	volatile int8u HighTemp:1;
	volatile int8u level:1;
}Flags;

enum {TEMPERATURE = 0, WATER_LEVEL};

//DEFINE MACROS

//FUNCTION PROTOTYPES
static void		init		(void);
static void		tmr2init	(void);
static void		Flagsinit	(void);
static void 	disptitl 	(void);
static void		DispParam	(void);
static void		TempCtrl	(void);
static void		WaterLevel	(void);

#endif
