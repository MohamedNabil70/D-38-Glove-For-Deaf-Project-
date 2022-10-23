/*
 * LCD_interface.h
 *
 * Created: 9/11/2022 11:33:19 AM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

// MACROS For LCD Bit Mode
#define LCD_4_BIT_MODE	4
#define LCD_8_BIT_MODE	8
// MACROS For LCD Shift Direction
#define LCD_SHIFT_LEFT	0
#define LCD_SHIFT_RIGHT	1

// MACROS For LCD Line Number
#define LCD_LINE_ONE 1
#define LCD_LINE_TWO 2


//Main Functions
void LCD_setPinDirections(void);
void LCD_init(void);
void LCD_sendCmnd(u8 cmnd);
void LCD_sendChar(u8 data);

static void writeHalfPort(u8 value);

//OTHER Functions
void LCD_sendString(u8* data);
void LCD_typeString(u8* data);  //Send string with typing effect
void LCD_writeNumber(u32 number);
void LCD_clear(void);
void LCD_shift(u8 shiftDirection);
void LCD_goToSpecificPosition(u8 lineNumber,u8 position);

/*
void LCD_writeSpecialCharacter(u8* pattern,u8 charPosition,u8 lineNumber,u8 position);
*/



#endif /* LCD_INTERFACE_H_ */