/*
 * MARGINS.c
 *
 *  Created on: 2018. jan. 8.
 *      Author: Armin
 */
#include "main.h"

extern GPIO_InitTypeDef marginsw;
extern int x_zero_reached;	// x sensor to D9 pin
extern int y_zero_reached;	// y sensor to D10 pin

void marginsw_init() {
		marginsw.Pin = GPIO_PIN_8;
		marginsw.Mode = GPIO_MODE_IT_RISING | GPIO_MODE_INPUT;
		marginsw.Pull = GPIO_PULLUP;
		marginsw.Speed = GPIO_SPEED_FAST;
		HAL_GPIO_Init(GPIOA, &marginsw);

		marginsw.Pin = GPIO_PIN_15;
		HAL_GPIO_Init(GPIOA, &marginsw);

		HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0x0A, 0);	// maybe adjust priority
		HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
		HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0A, 0);	// maybe adjust priority
		HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
		HAL_NVIC_SetPriority(SysTick_IRQn, 0x09 ,0);	// can be deleted after testing

		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) == GPIO_PIN_SET){
			y_zero_reached = 1;
			printf("y_zero_reached: %d\n", y_zero_reached);
		}


		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) == GPIO_PIN_SET){
			x_zero_reached = 1;
			printf("x_zero_reached: %d\n", x_zero_reached);
		}


}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	if (GPIO_Pin == GPIO_PIN_15) {
			x_zero_reached = 1;			// signal flag
	}

	if (GPIO_Pin == GPIO_PIN_8) {
		y_zero_reached = 1;			// signal flag
	}

}
void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
}
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}
