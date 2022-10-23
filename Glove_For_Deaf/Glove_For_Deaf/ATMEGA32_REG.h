/*
 * ATMEGA32_REG.h
 *
 * Created: 9/6/2022 11:37:21 AM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 


#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

					
						/*  DIO REGISTERS  */

//PORT_A_REGISTERS
#define PORTA (*(volatile u8*)0x3B) //output reg
#define DDRA  (*(volatile u8*)0x3A) //direction reg
#define PINA  (*(volatile u8*)0x39) //input reg
//PORT_B_REGISTERS
#define PORTB (*(volatile u8*)0x38)
#define DDRB  (*(volatile u8*)0x37)
#define PINB  (*(volatile u8*)0x36)
//PORT_C_REGISTERS
#define PORTC (*(volatile u8*)0x35)
#define DDRC  (*(volatile u8*)0x34)
#define PINC  (*(volatile u8*)0x33)
//PORT_D_REGISTERS
#define PORTD (*(volatile u8*)0x32)
#define DDRD  (*(volatile u8*)0x31)
#define PIND  (*(volatile u8*)0x30)

/******************************************************************************************/

						/*  EXTERNAL INTERRUPT REGISTERS  */

#define MCUCR		(*(volatile u8*)0x55) //MCU CONTROL Reg

#define MCUCSR		(*(volatile u8*)0x54) //MCU CONTROL & STATUS Reg

#define GICR		(*(volatile u8*)0x5B) //GENERAL INTERRUPT CONTROL Reg

#define GIFR		(*(volatile u8*)0x5A) //GENERAL INTERRUPT FLAG Reg

#define SREG		(*(volatile u8*)0x5F) //STATUS Reg
  
/******************************************************************************************/

							/*  ADC REGISTERS  */

//ADC Multiplexer Selection Register
#define ADMUX	 (*(volatile u8*)0x27)

//ADC Control and Status Register A 
#define ADCSRA	 (*(volatile u8*)0x26)

//The ADC Data Registers
#define ADCH	 (*(volatile u8*)0x25)
#define ADCL	 (*(volatile u8*)0x24)          
#define ADC_u16	 (*(volatile u16*)0x24)

//Special FunctionIO Register 
#define SFIOR	 (*(volatile u8*)0x50)

/******************************************************************************************/
							/*  TIMERS REGISTERS  */
					


//Timer/Counter Interrupt Mask Register
#define TIMSK	 (*(volatile u8*)0x59)

//Timer/Counter Interrupt Flag Register
#define TIFR	 (*(volatile u8*)0x58)

					
		/*  TIMER0 REGISTERS  */


//Timer/Counter Control Register							
#define TCCR0	 (*(volatile u8*)0x53)							

//Timer/Counter Register							
#define TCNT0	 (*(volatile u8*)0x52)

//Output Compare Register
#define OCR0	 (*(volatile u8*)0x5C)


						

		/*  TIMER1 REGISTERS  */

//Timer/Counter1 Control Register A
#define TCCR1A			(*(volatile u8*)0x4F)

//Timer/Counter1 Control Register B
#define TCCR1B			(*(volatile u8*)0x4E)
	
//Timer/Counter1 – TCNT1H and TCNT1L
#define TCNT1_u16		(*(volatile u16*)0x4C)	

//Output Compare Register 1 A – OCR1AH and OCR1AL
#define OCR1A_u16		(*(volatile u16*)0x4A)

//Output Compare Register 1 B – OCR1BH and OCR1BL
#define OCR1B_u16		(*(volatile u16*)0x48)

//Input Capture Register 1 – ICR1H and ICR1L
#define ICR1_u16		(*(volatile u16*)0x46)	

							
		/* WATCH DOG TIMER REGISTERS  */

//Watchdog Timer Control Register
#define WDTCR			(*(volatile u8*)0x41)
 
 							

/******************************************************************************************/

							/*  USART REGISTERS  */


// USART I/O Data Register 
#define UDR  (*(volatile u8*)0x2C)

//USART Control and Status Register A 
#define UCSRA (*(volatile u8*)0x2B)

//USART Control and Status Register B
#define UCSRB (*(volatile u8*)0x2A)

//USART Control and Status Register C
#define UCSRC (*(volatile u8*)0x40)

//USART Baud Rate Registers
#define UBRRL (*(volatile u8*)0x29)
#define UBRRH (*(volatile u8*)0x40)


/******************************************************************************************/
							
							/*  SPI REGISTERS  */
							
/*using different way can only be used if registers are following each other in address*/

typedef struct
{
u8 SPCR;	
u8 SPSR;
u8 SPDR;	
}SPI_REGS;

#define SPI		((volatile SPI_REGS*)0x2D)   



/******************************************************************************************/
							
							/*  TWI REGISTERS  */

// TWI Control Register
#define TWCR (*(volatile u8*)0x56)

// TWI Data Register
#define TWDR (*(volatile u8*)0x23)

// TWI (Slave) Address Register
#define TWAR (*(volatile u8*)0x22)

// TWI Status Register
#define TWSR (*(volatile u8*)0x21)

// TWI Bit Rate Register
#define TWBR (*(volatile u8*)0x20)


/******************************************************************************************/

#endif /* ATMEGA32_REG_H_ */