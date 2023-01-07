#include "GPIO.h"

void ConfigurationPin (GPIO_t *GPIOx, GPIO_PinConfig_t *PinConfig,
		       uint8_t Configuration, uint8_t PinModeMask)
{
  if (Configuration == LOW)
    {
      switch (PinConfig->GPIO_PinNumber)
	{
	case GPIO_PIN_0:
	  GPIOx->CRL.CNF0 = PinModeMask;
	  GPIOx->CRL.MODE0 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_1:
	  GPIOx->CRL.CNF1 = PinModeMask;
	  GPIOx->CRL.MODE1 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_2:
	  GPIOx->CRL.CNF2 = PinModeMask;
	  GPIOx->CRL.MODE2 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_3:
	  GPIOx->CRL.CNF3 = PinModeMask;
	  GPIOx->CRL.MODE3 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_4:
	  GPIOx->CRL.CNF4 = PinModeMask;
	  GPIOx->CRL.MODE4 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_5:
	  GPIOx->CRL.CNF5 = PinModeMask;
	  GPIOx->CRL.MODE5 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_6:
	  GPIOx->CRL.CNF6 = PinModeMask;
	  GPIOx->CRL.MODE6 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_7:
	  GPIOx->CRL.CNF7 = PinModeMask;
	  GPIOx->CRL.MODE7 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	default:
	  break;
	}
    }
  else
    {
      switch (PinConfig->GPIO_PinNumber)
	{
	case GPIO_PIN_8:
	  GPIOx->CRH.CNF8 = PinModeMask;
	  GPIOx->CRH.MODE8 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_9:
	  GPIOx->CRH.CNF9 = PinModeMask;
	  GPIOx->CRH.MODE9 = PinConfig->GPIO_OUTPUT_SPEED;
	  ;
	  break;
	case GPIO_PIN_10:
	  GPIOx->CRH.CNF10 = PinModeMask;
	  GPIOx->CRH.MODE10 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_11:
	  GPIOx->CRH.CNF11 = PinModeMask;
	  GPIOx->CRH.MODE11 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_12:
	  GPIOx->CRH.CNF12 = PinModeMask;
	  GPIOx->CRH.MODE12 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_13:
	  GPIOx->CRH.CNF13 = PinModeMask;
	  GPIOx->CRH.MODE13 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_14:
	  GPIOx->CRH.CNF14 = PinModeMask;
	  GPIOx->CRH.MODE14 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	case GPIO_PIN_15:
	  GPIOx->CRH.CNF15 = PinModeMask;
	  GPIOx->CRH.MODE15 = PinConfig->GPIO_OUTPUT_SPEED;
	  break;
	default:
	  break;
	}
    }
}

void GPIO_Init (GPIO_t *GPIOx, GPIO_PinConfig_t *PinConfig)
{

  volatile uint8_t Configuration =
      (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? LOW : HIGH;

  switch (PinConfig->GPIO_MODE)
    {
    case GPIO_MODE_ANALOG:
      ConfigurationPin (GPIOx, PinConfig, Configuration, GPIO_MODE_ANALOG_MASK);
      break;
    case GPIO_MODE_Input_FLO:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Input_FLO_MASK);
      break;
    case GPIO_MODE_Input_PU:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Input_PU_MASK);

      GPIOx->ODR._ODR |= PinConfig->GPIO_PinNumber;
      break;
    case GPIO_MODE_Input_PD:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Input_PD_MASK);
      break;
    case GPIO_MODE_Output_pp:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Output_pp_MASK);
      break;
    case GPIO_MODE_Output_OD:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Output_OD_MASK);
      break;
    case GPIO_MODE_Output_AF_PP:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Output_AF_PP_MASK);
      break;
    case GPIO_MODE_Output_AF_OD:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Output_AF_OD_MASK);
      break;
    case GPIO_MODE_Iuput_AF:
      ConfigurationPin (GPIOx, PinConfig, Configuration,
      GPIO_MODE_Iuput_AF_MASK);
      break;
    }
}

void GPIO_DeInit (GPIO_t *GPIOx)
{

  if (GPIOx == GPIOA)
    {
      RCC->APB2RSTR.IOPARST = TRUE;
      RCC->APB2RSTR.IOPARST = FALSE;
    }
  else if (GPIOx == GPIOB)
    {
      RCC->APB2RSTR.IOPBRST = TRUE;
      RCC->APB2RSTR.IOPBRST = FALSE;
    }
  else if (GPIOx == GPIOC)
    {
      RCC->APB2RSTR.IOPCRST = TRUE;
      RCC->APB2RSTR.IOPCRST = FALSE;
    }
  else if (GPIOx == GPIOD)
    {
      RCC->APB2RSTR.IOPDRST = TRUE;
      RCC->APB2RSTR.IOPDRST = FALSE;
    }
  else
    {
      RCC->APB2RSTR.IOPERST = TRUE;
      RCC->APB2RSTR.IOPERST = FALSE;
    }
}

uint8_t GPIO_ReadPin (GPIO_t *GPIOx, uint16_t PinNumber)
{
  return ((((GPIOx->IDR._IDR) & PinNumber) == PinNumber) ? TRUE : FALSE);
}

uint16_t GPIO_ReadPort (GPIO_t *GPIOx)
{
  return ((uint16_t) GPIOx->IDR._IDR);
}

void GPIO_WritePin (GPIO_t *GPIOx, uint16_t PinNumber, uint8_t Value)
{

  if (Value == TRUE)
    GPIOx->BSRR.BS = (uint16_t) PinNumber;
  else
    GPIOx->BSRR.BR = (uint16_t) PinNumber;
}

void GPIO_WritePort (GPIO_t *GPIOx, uint16_t Value)
{
  GPIOx->ODR._ODR = (uint32_t) Value;
}

void GPIO_TogglePin (GPIO_t *GPIOx, uint16_t PinNumber)
{
  GPIOx->ODR._ODR ^= PinNumber;
}

