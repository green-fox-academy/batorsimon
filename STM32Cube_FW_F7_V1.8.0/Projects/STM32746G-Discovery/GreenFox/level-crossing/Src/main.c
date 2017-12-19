/**
 ******************************************************************************
 * @file    Templates/Src/main.c
 * @author  MCD Application Team
 * @version V1.0.3
 * @date    22-April-2016
 * @brief   STM32F7xx HAL API Template project
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
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

/*     EXAM :
 *
     * TASK SUMMARY:
     * You need to implement a system which simulates a railway level crossing.
     *
     * SPECIFICATION:
     * 1. The initial state of the system is OPEN, so it allows cars passing. In this state
     *    the LED_GREEN should be flashing with 0.5Hz, 50% duty cycle
     * 2. When the system gets a signal that a train is approaching the crossing (blue
     *    button click) it has to enter into SECURING state. In SECURING state the system
     *    has to close the barrier which this takes exactly 5 seconds. In this state the
     *    LED_GREEN should be flashing with 1Hz, 50% duty cycle. During this time the system
     *    should not react to any further signal (blue button click).
     * 3. Once the barrier is down the system enters into SECURED state. In this state the
     *    LED_GREEN is turned constantly off.
     * 4. When the system gets a signal that a train has left the crossing (blue button
     *    click) it switches to OPENING state: lifts the barrier which takes exactly 6
     *    seconds (it's a heavy barrier so it takes more time to lift). In this state the
     *    LED_GREEN is flashing with 1Hz, 50% duty cycle. During this time the system
     *    should not react to any further signal (blue button click). Once the barrier
     *    is up, the system get's back to it's initial, OPEN state (point 1.).
     *
     * NON FUNCTIONAL REQUIREMENTS:
     * 1. You cannot read the state of the blue button, use interrupts!
     * 2. You should use at least 1 timer peripheral
     * 3. Try to avoid the use of blocking waiting mechanisms (like HAL_Delay())
     * 4. Using PWM on LED_GREEN is possible, but not required. Note that you have no
     *    timer channel to LED_GREEN, so to drive it from PWM you should turn on the LED
     *    in every timer period end interrupt, and turn it off in every PWM pulse end
     *    interrupt.
     * 5. When you enter to any state, you should report this on USART1 peripheral. You
     *    can use BSP_COM_Init() to initialize this, and a serial monitor to read these
     *    reports. It should look something like this after reset and a train crossing:
     *
     *    Entered in OPEN state         // some time later a click comes
     *    Entered in SECURING state
     *    Entered in SECURED state      // some time later a click comes
     *    Entered in OPENING state
     *    Entered in OPEN state
     */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <string.h>

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
 set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/** @addtogroup STM32F7xx_HAL_Examples
 * @{
 */

/** @addtogroup Templates
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef UartHandle;

void printing();
void TimerITInit();
TIM_HandleTypeDef TimHandle;
TIM_OC_InitTypeDef sConfig;

int i = 1;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void Peripherials_Config(void);
static void UART_Config(void);

/* Private functions ---------------------------------------------------------*/

/**
 * @brief  Main program
 * @param  None
 * @retval None
 */
int main(void) {
    Peripherials_Config();
  	printing();
  	TimerITInit();

  	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
  	BSP_LED_Init(LED_GREEN);

  	HAL_NVIC_SetPriority(BUTTON_KEY, 12, 0x00);
  	HAL_NVIC_EnableIRQ(BUTTON_KEY);

  	  HAL_NVIC_SetPriority(TIM2_IRQn, 13, 0x00);
  	  HAL_NVIC_EnableIRQ(TIM2_IRQn);

  	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0E, 0x00);
  	  	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

    while (1) {

    	 BSP_LED_Toggle(LED_GREEN);
    	HAL_Delay(200);

    	 if(BSP_PB_GetState(BUTTON_KEY) == 1){
    				 for(int j=0; j< 7; j++){
    					 BSP_LED_Toggle(LED_GREEN);
    					 printf("The lever is opening\n");
    					 HAL_Delay(100);
    				 }
    				 	printf("The lever is opened\n\n");
    				 	HAL_Delay(200);
    		 }

    		 if(BSP_PB_GetState(BUTTON_KEY) == 1){
    					 for(int j=0; j< 5; j++){
    								 BSP_LED_Toggle(LED_GREEN);
    								 printf("The lever is closing\n");
    								 HAL_Delay(100);
    					  }
    					printf("The lever is closed\n\n");
    					HAL_Delay(200);
    			 }

    }
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(BUTTON_KEY);
}


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	 printf("The lever is closing\n");
	BSP_LED_Toggle(LED_GREEN);
}



void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	// BSP_LED_Toggle(LED_GREEN);

/*
	 i++;
	 if(i%2==0){
		 printf("The lever is opening\n");
		 for(int j=0; j< 7; j++){
			 BSP_LED_Toggle(LED_GREEN);
		 }
		 	printf("The lever is opened\n\n");
	 } else{
		 printf("The lever is closing\n");
		 for(int j=0; j< 5; j++){
					 BSP_LED_Toggle(LED_GREEN);
		  }
		printf("The lever is closed\n\n");
	 }

	printf("waiting\n\n");
*/

}


void printing(){
		printf("\n");
		printf("****************************************************\n");
		printf("          Welcome to train project!\n");
		printf("****************************************************\n\n");

}

void TimerITInit() {

	__HAL_RCC_TIM2_CLK_ENABLE();

	TimHandle.Instance               = TIM2;
	TimHandle.Init.Period            = 5000;
	TimHandle.Init.Prescaler         = 21599;  // counter  1sec
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&TimHandle);
	HAL_TIM_Base_Start_IT(&TimHandle);

	HAL_TIM_PWM_Init(&TimHandle);
		sConfig.OCMode       = TIM_OCMODE_PWM1;
		sConfig.Pulse		 = 0;
		HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
		HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);

}

static void Peripherials_Config(void) {
    /* This project template calls firstly two functions in order to configure MPU feature
     and to enable the CPU Cache, respectively MPU_Config() and CPU_CACHE_Enable().
     These functions are provided as template implementation that User may integrate
     in his application, to enhance the performance in case of use of AXI interface
     with several masters. */

    /* Configure the MPU attributes as Write Through */
    MPU_Config();

    /* Enable the CPU Cache */
    CPU_CACHE_Enable();

    /* STM32F7xx HAL library initialization:
     - Configure the Flash ART accelerator on ITCM interface
     - Configure the Systick to generate an interrupt each 1 msec
     - Set NVIC Group Priority to 4
     - Low Level Initialization
     */
    HAL_Init();

    /* Configure the System clock to have a frequency of 216 MHz */
    SystemClock_Config();

    /*
     * Configure UART
     */
    UART_Config();
}

static void UART_Config(void) {
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &UartHandle);
}

/**
 * @brief  Retargets the C library printf function to the USART.
 * @param  None
 * @retval None
 */
PUTCHAR_PROTOTYPE {
    /* Place your implementation of fputc here */
    /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);

    return ch;
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 216000000
 *            HCLK(Hz)                       = 216000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 25
 *            PLL_N                          = 432
 *            PLL_P                          = 2
 *            PLL_Q                          = 9
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 7
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void) {
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    /* Enable HSE Oscillator and activate PLL with HSE as source */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 25;
    RCC_OscInitStruct.PLL.PLLN = 432;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = 9;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /* activate the OverDrive to reach the 216 Mhz Frequency */
    if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
        Error_Handler();
    }

    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1
            | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
    /* User may add here some code to deal with this error */
    while (1) {
    }
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
    MPU_Region_InitTypeDef MPU_InitStruct;

    /* Disable the MPU */
    HAL_MPU_Disable();

    /* Configure the MPU attributes as WT for SRAM */
    MPU_InitStruct.Enable = MPU_REGION_ENABLE;
    MPU_InitStruct.BaseAddress = 0x20010000;
    MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
    MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
    MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
    MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
    MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
    MPU_InitStruct.Number = MPU_REGION_NUMBER0;
    MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
    MPU_InitStruct.SubRegionDisable = 0x00;
    MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

    HAL_MPU_ConfigRegion(&MPU_InitStruct);

    /* Enable the MPU */
    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
    /* Enable I-Cache */
    SCB_EnableICache();

    /* Enable D-Cache */
    SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
