#ifndef _APP_H
#define _APP_H

/* Main settings */
#define TESTING

/******** MAIN CONFIGURATION ENDS ****************/

/* LCD CONFIGURATION */
#define LCD_DDR           	   		DDRC
#define LCD_DATA_PORT          		PORTC
#define LCD_ENABLE_PIN        		PC3 
#define LCD_REGISTER_SELECT_PIN     PC2
#ifdef TESTING
	#define DISPLAY_INIT				0
#else
	#define DISPLAY_INIT				1
#endif
#define LCD_NSCRL					0
#define FLOAT_T0_STRING				1
#define DECIMAL_PRECISION			100

/******** LCD CONFIGURATION ENDS ****************/

/* BUZZER: CONFIGURATION */
#define	BUZ_DDR						DDRC
#define	BUZ_PORT					PORTC
#define	BUZ_PIN						PC1
#define OFF_TIME					100
/******** BUZZER CONFIGURATION ENDS ****************/

/************* LED CONFIGURATION *****************/
#define	LED_DDR			DDRC
#define	LED_PORT		PORTC
#define	LED_PIN			PC0
#define OFF_TIME		100
/******** LED CONFIGURATION ENDS ****************/

/******** ADC CONFIGURATION ENDS ****************/
#define REF_VOL_256


/******** RELAY CONFIGURATION  ***************/
#define RLY_DDR			DDRD
#define RLY_PORT		PORTD
#define RLY1_PIN		PD6
#define RLY2_PIN		PD7
/******* RELAY CONFIGURATION ENDS    *********/

/****** HX711 24-BIT ADC CONFIGURATIONS *******/
#define HX711_DDR			DDRD
#define HX711_PORT			PORTD
#define HX711_INPIN			PIND
#define HX711_CLK_PIN		PD1
#define HX711_DIN_PIN		PD0

#define ATMOSPHERIC_PRESS	9500000
/****** HX711 24-BIT ADC CONFIGURATIONS ENDS*******/

/*********** RF CONFIGURATION ************/
#define RFDDR				DDRA
#define RFPORT				PORTA
#define RFEN_PIN			PA3
/*********** RF CONFIGURATION ENDS *******/

#endif
