/*
 * LCD_program.c
 *
 * Created: 9/11/2022 11:32:37 AM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 
 
#define F_CPU 16000000UL
#include <util/delay.h> 
	/*UTILES LIB*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"  

	/* MCAL */
#include "DIO_interface.h"

	/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"


		/*MAIN Functions*/
void LCD_setPinDirections(void)
{
/* LCD Data Pins Direction */
DIO_setPinDirection(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
DIO_setPinDirection(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
DIO_setPinDirection(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
DIO_setPinDirection(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);
/* LCD Control Pins Direction */
DIO_setPinDirection(LCD_E_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
DIO_setPinDirection(LCD_E_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
DIO_setPinDirection(LCD_E_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);
}		
void LCD_init(void)
{
_delay_ms(35);
#if LCD_MODE == LCD_4_BIT_MODE
	//set Rs pin to 0 (command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	//set Rw pin to 0 (write)
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);

	writeHalfPort(0b0010);
	//enable pulse H=>L
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
LCD_sendCmnd(0b00101000);
#elif LCD_MODE == LCD_8_BIT_MODE
LCD_sendCmnd(0b00111000);
#endif
_delay_us(45);
//display on,blink on, cursor on
LCD_sendCmnd(0b00001111);
_delay_us(45);
// clear display
LCD_sendCmnd(0b00000001);
_delay_ms(2);
//set 
LCD_sendCmnd(0b00000110);

}

void LCD_sendCmnd(u8 cmnd)
{
	//set Rs pin to 0 (command)
DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	//set Rw pin to 0 (write)
DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	
	DIO_setPortValue(LCD_DATA_PORT,cmnd);
	//enable pulse H=>L
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);

#elif LCD_MODE == LCD_4_BIT_MODE

	//write most Seg 4 bits of command
writeHalfPort(cmnd>>4);	
	//enable pulse H=>L
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
_delay_ms(1);
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//write least seg 4 bits command
writeHalfPort(cmnd);
	//enable pulse H=>L	
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
_delay_ms(1);
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);

	#endif
}

void LCD_sendChar(u8 data)
{
	//set Rs pin to 1 (data)
DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	//set Rw pin to 0 (write)
DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	
	DIO_setPortValue(LCD_DATA_PORT,data);
	//enable pulse H=>L
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);

	#elif LCD_MODE == LCD_4_BIT_MODE	
	//write most seg 4 bits of data
writeHalfPort(data>>4);	
	//enable pulse H=>L
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
_delay_ms(1);
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);
	//write least seg 4 bits of data
writeHalfPort(data);
	//enable pulse H=>L	
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_HIGH);
_delay_ms(1);
DIO_setPinValue(LCD_E_PORT,LCD_E_PIN,DIO_PIN_LOW);

	#endif	
}



static void writeHalfPort(u8 value)
{
if(1 == GET_BIT(value,0))
{
DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_HIGH);		
}else{
DIO_setPinValue(LCD_D4_PORT,LCD_D4_PIN,DIO_PIN_LOW);	
}
if(1 == GET_BIT(value,1))
{
DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_HIGH);		
}else{                           
DIO_setPinValue(LCD_D5_PORT,LCD_D5_PIN,DIO_PIN_LOW);	
}
if(1 == GET_BIT(value,2))
{
DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_HIGH);		
}else{
DIO_setPinValue(LCD_D6_PORT,LCD_D6_PIN,DIO_PIN_LOW);	
}
if(1 == GET_BIT(value,3))
{
DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_HIGH);		
}else{
DIO_setPinValue(LCD_D7_PORT,LCD_D7_PIN,DIO_PIN_LOW);	
}
		
}


		/*OTHER Functions*/

void LCD_sendString(u8* data)
{
	if (data != NULL)
	{
		u8 count=0;
		while (data[count] != '\0')
		{
			LCD_sendChar(data[count]);
			count++;
		}
		
	}

}

void LCD_typeString(u8* data)
{
	if (data != NULL)
	{
		u8 count=0;
		while (data[count] != '\0')
		{
			LCD_sendChar(data[count]);
			_delay_ms(65);
			count++;
		}
		
	}

}


void LCD_writeNumber(u32 number)  //Written by Eng Kareem
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		LCD_sendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do 
		{
			LCD_sendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	} 
}

void LCD_clear(void)
{
	// Clear display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
}

void LCD_shift(u8 shiftDirection)
{
	if (shiftDirection == LCD_SHIFT_LEFT)
	{
			LCD_sendCmnd(0b00011000);
			_delay_ms(10);
	}else if(shiftDirection == LCD_SHIFT_RIGHT){
	
			LCD_sendCmnd(0b00011100);
			_delay_ms(10);

	}
}

void LCD_goToSpecificPosition(u8 lineNumber,u8 position)
{
	if(lineNumber == LCD_LINE_ONE)
	{
	if (position<16)
	{
	LCD_sendCmnd(0x80 + position);	
	}
		
	}else if (lineNumber == LCD_LINE_TWO){
	if (position<16)
	{
	LCD_sendCmnd(0xC0 + position);		
	}	
	}
}


/*
void LCD_writeSpecialCharacter(u8* pattern,u8 charPosition,u8 lineNumber,u8 position)
{
	
}
*/

