/*
 * FINAL_interface.h
 *
 * Created: 10/18/2022 10:01:50 PM
 *  Author: Mohamed Nabil Mohamed, Ahmed Alaa Lotfy, Ahmed Hussein Mohamed
 */ 


#ifndef FINAL_INTERFACE_H_
#define FINAL_INTERFACE_H_


// (FINGER_1>860)  && (FINGER_2>980)  && (FINGER_3>980)  && (FINGER_4>950)  && (FINGER_5>425)   [ ideal  values for analog Readings ]


/* MACROS FOR FINGERS ANALOG VALUES */
#define FINGER_1  analogValue5
#define FINGER_2  analogValue4
#define FINGER_3  analogValue7
#define FINGER_4  analogValue6
#define FINGER_5  analogValue2



void FLEX_init(void);
void FLEX_getAnalogValue(void);
void FLEX_translateSign(void);
void FLEX_displyVal(void);




#endif /* FINAL_INTERFACE_H_ */