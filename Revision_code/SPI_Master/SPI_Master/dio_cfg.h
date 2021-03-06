/*
 * dio_cfg.h
 *
* Created: 6/12/2020:57:24 PM
* Author : abdelrahman_magdy
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_
#include "STD_Types.h"
#include "dio_types.h"
#include "dio_hw.h"
#include "bit_math.h"
#include "dio.h"

#define PINCOUNT   32
typedef struct{
	Dio_DirType pinDirection;
	STD_levelType pinState;
	}Dio_pin_configType;
extern const Dio_pin_configType Dio_pin_config [];


void Dio_init(void);

#endif /* DIO_CFG_H_ */