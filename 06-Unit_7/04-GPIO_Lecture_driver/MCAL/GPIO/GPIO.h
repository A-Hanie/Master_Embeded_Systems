#ifndef GPIO_H_
#define GPIO_H_


#include "../../MCAL/stm32f103c6.h"



typedef struct{


	uint16_t GPIO_PinNumber;



	uint8_t GPIO_MODE;



	uint8_t GPIO_OUTPUT_SPEED;
}GPIO_PinConfig_t;




#define GPIO_PIN_0                     ((uint16_t)0x0001)
#define GPIO_PIN_1                     ((uint16_t)0x0002)
#define GPIO_PIN_2                     ((uint16_t)0x0004)
#define GPIO_PIN_3                     ((uint16_t)0x0008)
#define GPIO_PIN_4                     ((uint16_t)0x0010)
#define GPIO_PIN_5                     ((uint16_t)0x0020)
#define GPIO_PIN_6                     ((uint16_t)0x0040)
#define GPIO_PIN_7                     ((uint16_t)0x0080)
#define GPIO_PIN_8                     ((uint16_t)0x0100)
#define GPIO_PIN_9                     ((uint16_t)0x0200)
#define GPIO_PIN_10                    ((uint16_t)0x0400)
#define GPIO_PIN_11                    ((uint16_t)0x0800)
#define GPIO_PIN_12                    ((uint16_t)0x1000)
#define GPIO_PIN_13                    ((uint16_t)0x2000)
#define GPIO_PIN_14                    ((uint16_t)0x4000)
#define GPIO_PIN_15                    ((uint16_t)0x8000)
#define GPIO_PIN_ALL                   ((uint16_t)0xFFFF)



#define GPIO_MODE_ANALOG               0x00000000U
#define GPIO_MODE_Input_FLO            0x00000001U
#define GPIO_MODE_Input_PU             0x00000002U
#define GPIO_MODE_Input_PD             0x00000003U
#define GPIO_MODE_Output_pp            0x00000004U
#define GPIO_MODE_Output_OD            0x00000005U
#define GPIO_MODE_Output_AF_PP         0x00000006U
#define GPIO_MODE_Output_AF_OD         0x00000007U
#define GPIO_MODE_Iuput_AF             0x00000008U



#define GPIO_MODE_ANALOG_MASK          0x00U
#define GPIO_MODE_Input_FLO_MASK       0x01U
#define GPIO_MODE_Input_PU_MASK        0x10U
#define GPIO_MODE_Input_PD_MASK        0x10U
#define GPIO_MODE_Output_pp_MASK       0x00U
#define GPIO_MODE_Output_OD_MASK       0x01U
#define GPIO_MODE_Output_AF_PP_MASK    0x10U
#define GPIO_MODE_Output_AF_OD_MASK    0x11U
#define GPIO_MODE_Iuput_AF_MASK        0x01U



#define GPIO_SPEED_Input               0x00U
#define GPIO_SPEED_10MHZ               0x01U
#define GPIO_SPEED_2MHZ                0x02U
#define GPIO_SPEED_50MHZ               0x03U



#define HIGH                           1U
#define LOW                            0U
#define OUTPUT                         1U
#define INPUT                          0U



void GPIO_Init          (GPIO_t* GPIOx , GPIO_PinConfig_t* PinConfig);
void GPIO_DeInit        (GPIO_t* GPIOx);


uint8_t   GPIO_ReadPin  (GPIO_t* GPIOx , uint16_t PinNumber);
uint16_t  GPIO_ReadPort (GPIO_t* GPIOx);


void GPIO_WritePin      (GPIO_t* GPIOx , uint16_t PinNumber , uint8_t Value);
void GPIO_WritePort     (GPIO_t* GPIOx , uint16_t Value);

void GPIO_TogglePin     (GPIO_t* GPIOx , uint16_t PinNumber);

Return_t GPIO_LockPin   (GPIO_t* GPIOx , uint16_t PinNumber);

#endif
