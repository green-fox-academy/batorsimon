#include "main.h"
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "string.h"
#include "UART.h"
#include "GCODE.h"

void UART_Config(UART_HandleTypeDef *huart) {

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	__HAL_RCC_USART1_CLK_ENABLE();

	UartTransmit.Pin 		= GPIO_PIN_9;
	UartTransmit.Mode       = GPIO_MODE_AF_PP;
	UartTransmit.Pull		= GPIO_PULLUP;
	UartTransmit.Speed 		= GPIO_SPEED_FAST;
	UartTransmit.Alternate  = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &UartTransmit);

	UartRecieve.Pin 		= GPIO_PIN_7;
	UartRecieve.Mode        = GPIO_MODE_AF_PP;
	UartRecieve.Speed 		= GPIO_SPEED_FAST;
	UartRecieve.Alternate   = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &UartRecieve);

	huart->Instance = USART1;
	huart->Init.BaudRate = 115200;
	huart->Init.WordLength = UART_WORDLENGTH_8B;
	huart->Init.StopBits = UART_STOPBITS_1;
	huart->Init.Parity = UART_PARITY_NONE;
	huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart->Init.Mode = UART_MODE_TX_RX;

	HAL_NVIC_SetPriority(USART1_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&UartHandle);
}

void UART_Buffer_Reset()
{
	memset(&G_Code_Buffer[0], '\0', sizeof(G_Code_Buffer));
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {

	if (Receive_Index == 0) { 								// If Index is at 0, reset buffers.
		UART_Buffer_Reset();

	} if (UART_IT_Data != '\n') {							// Copy to buffer until newline.
		G_Code_Buffer[Receive_Index++] = UART_IT_Data;
	} else {
		G_Code_Buffer[Receive_Index + 1] = UART_IT_Data;	// Add a newline for the tokenizer function.
		Receive_Index = 0;									// Reset index for new receive command.
	}

	HAL_UART_Receive_IT(&UartHandle, &UART_IT_Data, 1);		// Reinit interrupt for the new bit.

}


PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&UartHandle, (uint8_t *) &ch, 1, 0xFFFF);
    return ch;
}
