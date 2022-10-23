/*
 * ADC Driver.c
 *
 * Created: 9/20/2022 11:51:34 AM
 * Author : Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>	

	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "ADC_interface.h"
	#include "DIO_interface.h"
	#include "LCD_interface.h"
	#include "LCD_config.h"


	/* HAL */
	#include "FLEX_interface.h"

u16 analogValue2,analogValue4,analogValue5,analogValue6,analogValue7;

int main(void)
{
	
    LCD_setPinDirections();
	FLEX_init();	
	
	ADC_init();
	LCD_init();

	
	
	while (1) 
    {
		
 FLEX_getAnalogValue();

 FLEX_translateSign();

   
   

   _delay_ms(400);
   LCD_clear();

	}
	

}

