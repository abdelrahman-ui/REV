/*
 * ADC.h
 *
 * Created: 7/16/2020 3:08:03 PM
 *  Author: User™
 */ 


#ifndef ADC_H_
#define ADC_H_


#define V_ref 2.56
#define Step_size 2^10

unsigned int ADC_Read(unsigned channel);
void ADC_Init();
unsigned int ADC_Read_2(unsigned channel);

#endif /* ADC_H_ */