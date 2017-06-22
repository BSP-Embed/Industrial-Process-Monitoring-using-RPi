#include "main.h"

extern int8u lcdptr;

int main(void)
{
	int8u state = TEMPERATURE;
	
	init();
	while (TRUE) {
		if (Flags.Meas) {
			Flags.Meas = FALSE;
			switch(state) {
				case TEMPERATURE:	TempCtrl(); state = WATER_LEVEL; break;
				case WATER_LEVEL:	WaterLevel(); state = TEMPERATURE; break;
			}
		}
		sleep();
	}
	return 0;
}

static void WaterLevel(void)
{
	
	int8u level;
	char levelstr[10];
	char msg[10];
	
	msg[0] = '\0';
	
	level = (int8u) MeasPres(0xc6);
	
	if (level < LOW_LEVEL) {
		if (!Flags.level) {
			Flags.level = TRUE;
			rly2on();
			lcdptr = 0xcd;
			lcdws("ON ");
		}
	} else 	if (level >= HIGH_LEVEL) {
		if (Flags.level) {
			Flags.level = FALSE;
			rly2off();
			lcdptr = 0xcd;
			lcdws("OFF");
		}
	}
	ftoa(level, levelstr, 1);
	
	strcat(msg, "L");
	strcat(msg, levelstr);
	
	trans(msg);
	
}

static void TempCtrl(void)
{
	float temp;
	char tempstr[10];
	char msg[10];
	
	msg[0] = '\0';
		
	temp = readtemp(0x85);
		
	if (temp > HIGH_THRESHOLD) {
			if (!Flags.HighTemp) {
				Flags.HighTemp = TRUE;
				rly1on();
				lcdptr = 0x8D;
				lcdws("ON ");
			}
	} else 	if (temp < (HIGH_THRESHOLD - DELTA)) {
			if (Flags.HighTemp) {
				Flags.HighTemp = FALSE;
				rly1off();
				lcdptr = 0x8D;
				lcdws("OFF");
			}
	}
	
	ftoa(temp, tempstr, 1);
	
	strcat(msg, "T");
	strcat(msg, tempstr);
	
	trans(msg);
}

static void init(void)
{
	buzinit();
	beep(2,75);
	ledinit();
	rlyinit();
	lcdinit();
	adcinit();
	tmr2init();
	HX711init();
	Flagsinit();
	disptitl();
	DispParam();
	sei();
}

static void disptitl(void)
{
	lcdclr();
	lcdws("Global Industr'l");
	lcdr2();
	lcdws("Process Monito'g");
	dlyms(2000);
}
static void DispParam(void)
{
	lcdclr();
	lcdws("Temp:    'cD:");
	lcdr2();
	lcdws("Water:    %D:");
}
static void tmr2init(void)
{
	TCNT2   = 75;
	TIMSK   |= _BV(TOIE2);			//ENABLE OVERFLOW INTERRUPT
	TCCR2  |=  _BV(CS22) | _BV(CS21) | _BV(CS20); /* PRESCALAR BY 256 */
}

/* overflows at every 25msec */
ISR(TIMER2_OVF_vect)
{
	static int8u i;
	static int16u j;
	TCNT2 = 75;

	if (++i >= 200) i = 0;
	switch(i) {
		case 0: case 5: ledon(); break;
		case 1: case 6: ledoff(); break;
	}
	
	if (++j >= 400) {
		j = 0;
		Flags.Meas =  TRUE;
	}
	
}
static void Flagsinit(void)
{
	Flags.Meas = TRUE;
	Flags.HighTemp = FALSE;
	Flags.level = FALSE;
}
