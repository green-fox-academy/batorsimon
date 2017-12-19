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

typedef enum {
    STATE_OPEN,
    STATE_SECURING,
    STATE_SECURED,
    STATE_OPENING
} State;

typedef struct {
        State state;
        State nextState;
        uint8_t timerPeriodCounts;
        uint8_t ledTogglePeriodCounts;
} State_Config;

/* Private define ------------------------------------------------------------*/
#define TIMER_2HZ   TIM2

UART_HandleTypeDef UartHandle;
TIM_HandleTypeDef Tim2HzHandle;

volatile State_Config _currentState;
volatile uint8_t _periodCounter;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

static void Peripherals_Config(void);
static void Tim2Hz_Config_IT(void);
static void Tim2Hz_Start_IT(void);
static void Tim2Hz_Stop_IT(void);
static void State_Start(State newState);
static void UART_Config(void);
/* Private functions ---------------------------------------------------------*/

int main(void) {
    Peripherals_Config();
    State_Start(STATE_OPEN);
    while (1) {}  // no need it
}

static void State_Start(State newState) {
    Tim2Hz_Stop_IT();  // stop the timer

    _currentState.state = newState;  // I set the new state
    switch (newState) {
        case STATE_OPEN:
            printf("Entering OPEN state\r\n");          // send the string to UART according to the specs
            _currentState.nextState = STATE_SECURING;   // the next state is STATE_SECURING
            _currentState.ledTogglePeriodCounts = 2;    // 0.5Hz flashing, so 2*0.5sec period
            _currentState.timerPeriodCounts = 0;        // the state remains until external interrupt
            break;
        case STATE_SECURING:
            printf("Entering SECURING state\r\n");      // send the string to UART according to the specs
            _currentState.nextState = STATE_SECURED;    // the next state is STATE_SECURED
            _currentState.ledTogglePeriodCounts = 1;    // 1Hz flashing, so 1*0.5sec period
            _currentState.timerPeriodCounts = 10;       // 5sec = 10*0.5sec (10 timer periods)
            break;
        case STATE_SECURED:
            printf("Entering SECURED state\r\n");       // send the string to UART according to the specs
            _currentState.nextState = STATE_OPENING;    // the next state is STATE_OPENING
            _currentState.ledTogglePeriodCounts = 0;    // no flashing
            _currentState.timerPeriodCounts = 0;        // the state remains until external interrupt
            break;
        case STATE_OPENING:
            printf("Entering OPENING state\r\n");       // send the string to UART according to the specs
            _currentState.nextState = STATE_OPEN;       // the next state is STATE_OPEN
            _currentState.ledTogglePeriodCounts = 1;    // 1Hz flashing, so 1*0.5sec period
            _currentState.timerPeriodCounts = 12;       // 6sec = 12*0.5sec (12 timer periods)
            break;
    }
    // The LED should be flashed if the state is not SECURED so i start the timer with interrupts
    if (newState != STATE_SECURED) {
        Tim2Hz_Start_IT();
    }
}


static void Tim2Hz_Start_IT(void) {
    TIMER_2HZ->CNT = 0;
    _periodCounter = 0;
    BSP_LED_On(LED_GREEN);
    HAL_TIM_Base_Start_IT(&Tim2HzHandle);
}

static void Tim2Hz_Stop_IT(void) {
    BSP_LED_Off(LED_GREEN);
    HAL_TIM_Base_Stop_IT(&Tim2HzHandle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    _periodCounter++;
    if (_currentState.timerPeriodCounts && _currentState.timerPeriodCounts == _periodCounter) {
        State_Start(_currentState.nextState);
        return;
    }

    if (_currentState.ledTogglePeriodCounts && !(_periodCounter%_currentState.ledTogglePeriodCounts)) {
        BSP_LED_Toggle(LED_GREEN);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (_currentState.state == STATE_OPENING || _currentState.state == STATE_SECURING) {
        return;
    }
    State_Start(_currentState.nextState);
}

static void Peripherals_Config(void) {
    MPU_Config();
    CPU_CACHE_Enable();
    HAL_Init();
    SystemClock_Config();

    Tim2Hz_Config_IT();
    UART_Config();

    BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
    BSP_LED_Init(LED_GREEN);
}
static void Tim2Hz_Config_IT(void) {

    // TIM2's bus clock is: 108MHz, so 108 000 000 = 2*(Period+1)*(Prescaler+1)
    Tim2HzHandle.Instance = TIMER_2HZ;
    Tim2HzHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    Tim2HzHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    Tim2HzHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
    Tim2HzHandle.Init.Period = 9999;
    Tim2HzHandle.Init.Prescaler = 5399;

    HAL_TIM_Base_Init(&Tim2HzHandle);
    HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0);
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
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
