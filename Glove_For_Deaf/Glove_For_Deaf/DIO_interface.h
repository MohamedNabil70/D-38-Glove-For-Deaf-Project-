/*
 * DIO_interface.h
 *
 * Created: 06/09/2022 11:35:19
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//MACROS FOR PIN_ID
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
//MACROS FOR PIN DIRECTION
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT  0
//MACROS FOR PIN VALUE
#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0


//MACROS FOR PORT_ID
#define DIO_PORTA 0 
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//MACROS FOR PORT DIRECTION
#define DIO_PORT_OUTPUT	 0xff
#define DIO_PORT_INPUT   0x00
//MACROS FOR PIN VALUE
#define DIO_PORT_HIGH 	 0xff
#define DIO_PORT_LOW  	 0x00	


	/*Pin Apis*/
void DIO_setPinDirection		(u8 PortId,u8 PinId,u8 PinDirection);
void DIO_setPinValue			(u8 PortId,u8 PinId,u8 PinValue);
void DIO_getPinValue			(u8 PortId,u8 PinId,u8* PinValue);
void DIO_togglePinValue			(u8 PortId,u8 PinId);
void DIO_setInputPinResistence  (u8 PortId,u8 PinId);
	/*Port Apis*/
void DIO_setPortDirection		 (u8 PortId,u8 PortDirection);
void DIO_setPortValue			 (u8 PortId,u8 PortValue);
void DIO_getPortValue			 (u8 PortId,u8* PortValue);
void DIO_togglePortValue		 (u8 PortId);
void DIO_setInputPortResistence  (u8 PortId);

#endif /* DIO_INTERFACE_H_ */