/*
 * ADC_program.c
 *
 * Created: 9/20/2022 11:52:15 AM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 


	/*UTILES LIB*/
	#include "STD_TYPES.h"
	#include "BIT_MATH.h"
	#include "ATMEGA32_REG.h"

	/* MCAL */
	#include "ADC_interface.h"
	
	
	void ADC_init(void)
	{
	//Select Vref
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	//Select Right Adjustment
	CLR_BIT(ADMUX,5);
	
	//Single conversation mode (Auto trigger off)
	CLR_BIT(ADCSRA,5);

	//Disable interrupt Enable bit
	CLR_BIT(ADCSRA,3);

//Reduce CLK Frequency by factor of [128] (from 16 Mhz to 125 Khz)
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	//ADC Enable
	SET_BIT(ADCSRA,7);
	}
	
	
	void ADC_getDigitalValue(u8 channelNum , u16* digitalReading)
	{
		if ((channelNum<8) && (digitalReading!=NULL))
		{
		//clear only  ADC channel bits from ADMUX REG       
		ADMUX &= 0b11100000;			 
		//add only ADC channel bits to ADMUX REG	
		ADMUX |= channelNum;
		
		//Start Conversion
		SET_BIT(ADCSRA,6);
		
		//Polling with blocking for Flag
		while(GET_BIT(ADCSRA,4) == 0);
		
		//Clear flag by setting it to 1 (write 1 to clr)
		SET_BIT(ADCSRA,4);
		
		*digitalReading=ADC_u16;		

		}
	}
	
	void ADC_getAnalogValue(u8 channelNum, u16* analogReading)
	{
			u16 digitalVal;
			ADC_getDigitalValue(channelNum ,&digitalVal);
			
			*analogReading=(((u32)digitalVal*5000UL)/(1024));
				
	}

	

	
