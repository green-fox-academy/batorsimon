/*
 * MARGINS.h
 *
 *  Created on: 2018. jan. 8.
 *      Author: valaki
 */

#ifndef MARGINS_H_
#define MARGINS_H_

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void EXTI9_5_IRQHandler();
void EXTI15_10_IRQHandler();
void marginsw_init();

extern GPIO_InitTypeDef marginsw;
extern int x_zero_reached;	// x sensor to D9 pin
extern int y_zero_reached;	// y sensor to D10 pin

#endif /* MARGINS_H_ */
