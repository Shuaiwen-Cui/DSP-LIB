/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 06/06/2019 11:35:40
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            32000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            64000000
#define MX_HSE_VALUE                            25000000
#define MX_EXTERNAL_CLOCK_VALUE                 12288000
#define MX_PLLDSIFreq_Value                     500000000
#define MX_SYSCLKFreq_VALUE                     400000000
#define MX_HCLKFreq_Value                       200000000
#define MX_CortexFreq_Value                     400000000
#define MX_APB1Freq_Value                       100000000
#define MX_APB2Freq_Value                       100000000
#define MX_CECFreq_Value                        32000
#define MX_RTCFreq_Value                        32000
#define MX_USBFreq_Value                        48000000
#define MX_WatchDogFreq_Value                   32000
#define MX_DSIFreq_Value                        96000000
#define MX_DSIPHYCLKFreq_Value                  96000000
#define MX_DSITXEscFreq_Value                   20000000
#define MX_SPDIFRXFreq_Value                    20000000
#define MX_MCO1PinFreq_Value                    64000000
#define MX_MCO2PinFreq_Value                    400000000

/*-------------------------------- CORTEX_M7  --------------------------------*/

#define MX_CORTEX_M7                            1

/* GPIO Configuration */

/*-------------------------------- FDCAN1     --------------------------------*/

#define MX_FDCAN1                               1

/* GPIO Configuration */

/* Pin PA12 */
#define MX_FDCAN1_TX_GPIO_Speed                 GPIO_SPEED_FREQ_HIGH
#define MX_FDCAN1_TX_Pin                        PA12
#define MX_FDCAN1_TX_GPIOx                      GPIOA
#define MX_FDCAN1_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_FDCAN1_TX_GPIO_Pin                   GPIO_PIN_12
#define MX_FDCAN1_TX_GPIO_AF                    GPIO_AF9_FDCAN1
#define MX_FDCAN1_TX_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PA11 */
#define MX_FDCAN1_RX_GPIO_Speed                 GPIO_SPEED_FREQ_HIGH
#define MX_FDCAN1_RX_Pin                        PA11
#define MX_FDCAN1_RX_GPIOx                      GPIOA
#define MX_FDCAN1_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_FDCAN1_RX_GPIO_Pin                   GPIO_PIN_11
#define MX_FDCAN1_RX_GPIO_AF                    GPIO_AF9_FDCAN1
#define MX_FDCAN1_RX_GPIO_Mode                  GPIO_MODE_AF_PP

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

#endif  /* __MX_DEVICE_H */

