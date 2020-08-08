/*
 * dio.h
 *
* Created: 6/12/2020:57:24 PM
* Author : abdelrahman_magdy
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "dio_types.h"
#include "STD_Types.h"

void Dio_WriteChannel(Dio_ChannelType Channel, STD_levelType level);
void DIO_Read(Dio_ChannelType channel,uint8 *data);
void Dio_FlipChannel( Dio_ChannelType ChannelId);
STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId); //TODO
/*=========================================
 * FUNCTIONS PROTOTYPES
 =========================================*/
//STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId);
//uint8 Dio_ReadPort(Dio_PortType PortId );

/*void Dio_WritePort( Dio_PortType PortId, uint8 Level);
void Dio_FlipPort(Dio_PortType PortId);*/
#endif /* DIO_H_ */