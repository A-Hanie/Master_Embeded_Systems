
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "../../MCAL/GPIO/GPIO.h"

#define RS						GPIO_PIN_10
#define RW						GPIO_PIN_9
#define E						GPIO_PIN_8
#define LCD_DATA_0					GPIO_PIN_0
#define LCD_DATA_1			         	GPIO_PIN_1
#define LCD_DATA_2				    	GPIO_PIN_2
#define LCD_DATA_3				        GPIO_PIN_3
#define LCD_DATA_4					GPIO_PIN_4
#define LCD_DATA_5			         	GPIO_PIN_5
#define LCD_DATA_6				    	GPIO_PIN_6
#define LCD_DATA_7				        GPIO_PIN_7
#define LCD_MODE
#define LCD_SPEED

#define LCD_CONTROL_PORT                		GPIOA
#define LCD_DATA_PORT                   		GPIOA

#endif
