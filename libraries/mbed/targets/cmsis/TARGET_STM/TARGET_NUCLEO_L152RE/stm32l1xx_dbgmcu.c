/**
  ******************************************************************************
  * @file    stm32l1xx_dbgmcu.c
  * @author  MCD Application Team
  * @version V1.3.0
  * @date    31-January-2014
  * @brief   This file provides all the DBGMCU firmware functions.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_dbgmcu.h"

/** @addtogroup STM32L1xx_StdPeriph_Driver
  * @{
  */

/** @defgroup DBGMCU 
  * @brief DBGMCU driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define IDCODE_DEVID_MASK    ((uint32_t)0x00000FFF)

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup DBGMCU_Private_Functions
  * @{
  */

/**
  * @brief  Returns the device revision identifier.
  * @param  None
  * @retval Device revision identifier
  */
uint32_t DBGMCU_GetREVID(void)
{
   return(DBGMCU->IDCODE >> 16);
}

/**
  * @brief  Returns the device identifier.
  * @param  None
  * @retval Device identifier
  */
uint32_t DBGMCU_GetDEVID(void)
{
   return(DBGMCU->IDCODE & IDCODE_DEVID_MASK);
}

/**
  * @brief  Configures low power mode behavior when the MCU is in Debug mode.
  * @param  DBGMCU_Periph: specifies the low power mode.
  *   This parameter can be any combination of the following values:
  *     @arg DBGMCU_SLEEP: Keep debugger connection during SLEEP mode
  *     @arg DBGMCU_STOP: Keep debugger connection during STOP mode
  *     @arg DBGMCU_STANDBY: Keep debugger connection during STANDBY mode
  * @param  NewState: new state of the specified low power mode in Debug mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DBGMCU_PERIPH(DBGMCU_Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    DBGMCU->CR |= DBGMCU_Periph;
  }
  else
  {
    DBGMCU->CR &= ~DBGMCU_Periph;
  }
}


/**
  * @brief  Configures APB1 peripheral behavior when the MCU is in Debug mode.
  * @param  DBGMCU_Periph: specifies the APB1 peripheral.
  *   This parameter can be any combination of the following values:
  *     @arg DBGMCU_TIM2_STOP: TIM2 counter stopped when Core is halted
  *     @arg DBGMCU_TIM3_STOP: TIM3 counter stopped when Core is halted
  *     @arg DBGMCU_TIM4_STOP: TIM4 counter stopped when Core is halted
  *     @arg DBGMCU_TIM5_STOP: TIM5 counter stopped when Core is halted  
  *     @arg DBGMCU_TIM6_STOP: TIM6 counter stopped when Core is halted
  *     @arg DBGMCU_TIM7_STOP: TIM7 counter stopped when Core is halted
  *     @arg DBGMCU_RTC_STOP:
  *       + On STM32L1xx Medium-density devices: RTC Wakeup counter stopped when 
  *         Core is halted.
  *       + On STM32L1xx High-density and Medium-density Plus devices: RTC Calendar 
  *         and Wakeup counter stopped when Core is halted.
  *     @arg DBGMCU_WWDG_STOP: Debug WWDG stopped when Core is halted
  *     @arg DBGMCU_IWDG_STOP: Debug IWDG stopped when Core is halted
  *     @arg DBGMCU_I2C1_SMBUS_TIMEOUT: I2C1 SMBUS timeout mode stopped when Core is 
  *                                     halted
  *     @arg DBGMCU_I2C2_SMBUS_TIMEOUT: I2C2 SMBUS timeout mode stopped when Core is 
  *                                     halted
  * @param  NewState: new state of the specified APB1 peripheral in Debug mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DBGMCU_APB1PeriphConfig(uint32_t DBGMCU_Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DBGMCU_APB1PERIPH(DBGMCU_Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    DBGMCU->APB1FZ |= DBGMCU_Periph;
  }
  else
  {
    DBGMCU->APB1FZ &= ~DBGMCU_Periph;
  }
}

/**
  * @brief  Configures APB2 peripheral behavior when the MCU is in Debug mode.
  * @param  DBGMCU_Periph: specifies the APB2 peripheral.
  *   This parameter can be any combination of the following values:
  *     @arg DBGMCU_TIM9_STOP: TIM9 counter stopped when Core is halted
  *     @arg DBGMCU_TIM10_STOP: TIM10 counter stopped when Core is halted
  *     @arg DBGMCU_TIM11_STOP: TIM11 counter stopped when Core is halted
  * @param  NewState: new state of the specified APB2 peripheral in Debug mode.
  *   This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void DBGMCU_APB2PeriphConfig(uint32_t DBGMCU_Periph, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_DBGMCU_APB2PERIPH(DBGMCU_Periph));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    DBGMCU->APB2FZ |= DBGMCU_Periph;
  }
  else
  {
    DBGMCU->APB2FZ &= ~DBGMCU_Periph;
  }
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
