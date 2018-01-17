#ifndef UART_H_
#define UART_H_

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

char G_Code_Buffer[100];
uint8_t Receive_Index;
uint8_t UART_IT_Data;

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef UartTransmit;
 GPIO_InitTypeDef UartRecieve;


void UART_Config(UART_HandleTypeDef *huart);
void USART1_IRQHandler(void);
void UART_Buffer_Reset();
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);


#endif /* UART_H_ */
