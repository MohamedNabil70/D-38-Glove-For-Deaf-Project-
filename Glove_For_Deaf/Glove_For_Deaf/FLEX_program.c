/*
 * FLEX.c
 *
 * Created: 10/18/2022 10:00:45 PM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
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


extern u16 analogValue2,analogValue4,analogValue5,analogValue6,analogValue7;

void FLEX_init(void)
{
	// Set Directions
	DIO_setPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_INPUT);

	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_INPUT);
}

void FLEX_getAnalogValue(void)
{
	
		ADC_getAnalogValue(ADC_CHANNEL_2,&analogValue2);
		ADC_getAnalogValue(ADC_CHANNEL_4,&analogValue4);
		ADC_getAnalogValue(ADC_CHANNEL_5,&analogValue5);
		ADC_getAnalogValue(ADC_CHANNEL_6,&analogValue6);
		ADC_getAnalogValue(ADC_CHANNEL_7,&analogValue7);

	
}

void FLEX_translateSign(void)
{
	  if ((FINGER_1>860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"I Love You <3");
		  
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"That's Awesome !");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2>980)  && (FINGER_3>980)  && (FINGER_4>950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"HELLO !");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4<950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"Good Job");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3>980)  && (FINGER_4>950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"I'm Watching You");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"You !");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2<980)  && (FINGER_3>980)  && (FINGER_4>950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"I Really Love U");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4<950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"Sorry");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2>980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"Like ");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"Brother");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4<950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"Phone");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2>980)  && (FINGER_3>980)  && (FINGER_4<950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"Perfect");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2<980)  && (FINGER_3<980)  && (FINGER_4<950)  && (FINGER_5<425))
	  {
		  LCD_sendString((u8*)"End");
	  }
	  
	  else if ((FINGER_1<860)  && (FINGER_2<980)  && (FINGER_3>980)  && (FINGER_4>950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"Gun");
	  }
	  
	  else if ((FINGER_1>860)  && (FINGER_2>980)  && (FINGER_3<980)  && (FINGER_4>950)  && (FINGER_5>425))
	  {
		  LCD_sendString((u8*)"Favorite");
	  }
	  
	  
	  else
	  {
		  LCD_sendString((u8*)"Reading");
		  _delay_ms(55);
		  LCD_sendChar('.');
		  _delay_ms(55);
		  LCD_sendChar('.');
		  _delay_ms(55);
		  LCD_sendChar('.');
		  _delay_ms(55);
		  LCD_sendChar('.');
		  _delay_ms(30);
		  LCD_sendChar('.');
		  _delay_ms(30);
		  LCD_sendChar('.');
	  }
	  
}

void FLEX_displyVal(void)
{
	//write: >
	LCD_goToSpecificPosition(LCD_LINE_ONE,0);
	LCD_sendChar('>');
	LCD_goToSpecificPosition(LCD_LINE_ONE,6);
	LCD_sendChar('>');
	LCD_goToSpecificPosition(LCD_LINE_ONE,12);
	LCD_sendChar('>');

	LCD_goToSpecificPosition(LCD_LINE_TWO,0);
	LCD_sendChar('>');
	LCD_goToSpecificPosition(LCD_LINE_TWO,6);
	LCD_sendChar('>');





	//write analog Values
	LCD_goToSpecificPosition(LCD_LINE_ONE,1);
	LCD_writeNumber(analogValue4);
	LCD_goToSpecificPosition(LCD_LINE_ONE,7);
	LCD_writeNumber(analogValue5);
	LCD_goToSpecificPosition(LCD_LINE_ONE,13);
	LCD_writeNumber(analogValue2);


	LCD_goToSpecificPosition(LCD_LINE_TWO,1);
	LCD_writeNumber(analogValue6);
	LCD_goToSpecificPosition(LCD_LINE_TWO,7);
	LCD_writeNumber(analogValue7);


	LCD_goToSpecificPosition(LCD_LINE_TWO,15);
}

