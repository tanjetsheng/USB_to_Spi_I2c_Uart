/**
  ******************************************************************************
  * @file    stm32f1xx_hal.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_H
#define __STM32F1xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#define SPI_MODE_SLAVE                  0
#define SPI_MODE_MASTER                1
/**
  * @}
  */

/** @defgroup SPI_Direction SPI Direction Mode
  * @{
  */
#define SPI_DIRECTION_2LINES            0
#define SPI_DIRECTION_2LINES_RXONLY     1
#define SPI_DIRECTION_1LINE             2
/**
  * @}
  */

/** @defgroup SPI_Data_Size SPI Data Size
  * @{
  */
#define SPI_DATASIZE_8BIT               0
#define SPI_DATASIZE_16BIT              1
/**
  * @}
  */

/** @defgroup SPI_Clock_Polarity SPI Clock Polarity
  * @{
  */
#define SPI_POLARITY_LOW                0
#define SPI_POLARITY_HIGH               1
/**
  * @}
  */

/** @defgroup SPI_Clock_Phase SPI Clock Phase
  * @{
  */
#define SPI_PHASE_1EDGE                 0
#define SPI_PHASE_2EDGE                 1
/**
  * @}
  */

/** @defgroup SPI_Slave_Select_management SPI Slave Select Management
  * @{
  */
#define SPI_NSS_SOFT                    0
#define SPI_NSS_HARD_INPUT              1
#define SPI_NSS_HARD_OUTPUT             2
/**
  * @}
  */

/** @defgroup SPI_BaudRate_Prescaler SPI BaudRate Prescaler
  * @{
  */
#define SPI_BAUDRATEPRESCALER_2         0
#define SPI_BAUDRATEPRESCALER_4         1
#define SPI_BAUDRATEPRESCALER_8         2
#define SPI_BAUDRATEPRESCALER_16        3
#define SPI_BAUDRATEPRESCALER_32        4
#define SPI_BAUDRATEPRESCALER_64        5
#define SPI_BAUDRATEPRESCALER_128       6
#define SPI_BAUDRATEPRESCALER_256       7

/**
  * @}
  */

/** @defgroup SPI_MSB_LSB_transmission SPI MSB LSB Transmission
  * @{
  */
#define SPI_FIRSTBIT_MSB                0
#define SPI_FIRSTBIT_LSB                1
/**
  * @}
  */

/** @defgroup SPI_TI_mode SPI TI Mode
  * @{
  */
#define SPI_TIMODE_DISABLE             0
/**
  * @}
  */

/** @defgroup SPI_CRC_Calculation SPI CRC Calculation
  * @{
  */
#define SPI_CRCCALCULATION_DISABLE     0
#define SPI_CRCCALCULATION_ENABLE      1
/**
  * @}
  */

/** @defgroup SPI_Interrupt_definition SPI Interrupt Definition
  * @{
  */
#define SPI_IT_TXE                      0
#define SPI_IT_RXNE                     1
#define SPI_IT_ERR                      2
/**
  * @}
  */

/** @defgroup SPI_Flags_definition SPI Flags Definition
  * @{
  */
#define SPI_FLAG_RXNE                   0   /* SPI status flag: Rx buffer not empty flag */
#define SPI_FLAG_TXE                    1    /* SPI status flag: Tx buffer empty flag */
#define SPI_FLAG_BSY                    2    /* SPI status flag: Busy flag */
#define SPI_FLAG_CRCERR                 3 /* SPI Error flag: CRC error flag */
#define SPI_FLAG_MODF                   4   /* SPI Error flag: Mode fault flag */
#define SPI_FLAG_OVR                    5    /* SPI Error flag: Overrun flag */

#define I2C_DUTYCYCLE_2                 0
#define I2C_DUTYCYCLE_16_9              1
/**
  * @}
  */

/** @defgroup I2C_addressing_mode I2C addressing mode
  * @{
  */
#define I2C_ADDRESSINGMODE_7BIT         0
#define I2C_ADDRESSINGMODE_10BIT        1
/**
  * @}
  */

/** @defgroup I2C_dual_addressing_mode  I2C dual addressing mode
  * @{
  */
#define I2C_DUALADDRESS_DISABLE       0
#define I2C_DUALADDRESS_ENABLE        1
/**
  * @}
  */

/** @defgroup I2C_general_call_addressing_mode I2C general call addressing mode
  * @{
  */
#define I2C_GENERALCALL_DISABLE       0
#define I2C_GENERALCALL_ENABLE         1
/**
  * @}
  */

/** @defgroup I2C_nostretch_mode I2C nostretch mode
  * @{
  */
#define I2C_NOSTRETCH_DISABLE          0
#define I2C_NOSTRETCH_ENABLE           1

#define USART_WORDLENGTH_8B                  0
#define USART_WORDLENGTH_9B                 1
/**
  * @}
  */

/** @defgroup USART_Stop_Bits USART Number of Stop Bits
  * @{
  */
#define USART_STOPBITS_1                    0
#define USART_STOPBITS_0_5                   1
#define USART_STOPBITS_2                   2
#define USART_STOPBITS_1_5                   3
/**
  * @}
  */

/** @defgroup USART_Parity USART Parity
  * @{
  */
#define USART_PARITY_NONE                    0
#define USART_PARITY_EVEN                    1
#define USART_PARITY_ODD                     2
/**
  * @}
  */

/** @defgroup USART_Mode USART Mode
  * @{
  */
#define USART_MODE_RX                        0
#define USART_MODE_TX                        1
#define USART_MODE_TX_RX                     2
/**
  * @}
  */

/** @defgroup USART_Clock USART Clock
  * @{
  */
#define USART_CLOCK_DISABLE               0
#define USART_CLOCK_ENABLE                  1
/**
  * @}
  */

/** @defgroup USART_Clock_Polarity USART Clock Polarity
  * @{
  */
#define USART_POLARITY_LOW                 0
#define USART_POLARITY_HIGH                  1
/**
  * @}
  */

/** @defgroup USART_Clock_Phase USART Clock Phase
  * @{
  */
#define USART_PHASE_1EDGE                    0
#define USART_PHASE_2EDGE                  1
/**
  * @}
  */

/** @defgroup USART_Last_Bit USART Last Bit
  * @{
  */
#define USART_LASTBIT_DISABLE               0
#define USART_LASTBIT_ENABLE                 1


#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
