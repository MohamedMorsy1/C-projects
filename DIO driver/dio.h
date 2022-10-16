/*
 * dio.h
 *
 * Created: 9/23/2022 9:59:36 PM
 *  Author: Mohamed
 */ 

#include "../../utilities/registers.h"

#ifndef DIO_H_
#define DIO_H_

//define directions
#define IN 0
#define OUT 1

//define values
#define LOW 0
#define HIGH 1

typedef enum EN_DIO_ERROR_t
{
	OK, WRONG_PORT, WRONG_PIN, WRONG_DIRECTION, WRONG_VALUE
	}EN_DIO_ERROR_t;


EN_DIO_ERROR_t DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction);
EN_DIO_ERROR_t DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value);
EN_DIO_ERROR_t DIO_toggle(uint8_t portNum, uint8_t pinNum);
EN_DIO_ERROR_t DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value);

#endif /* DIO_H_ */