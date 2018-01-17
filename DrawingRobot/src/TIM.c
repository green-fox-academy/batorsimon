#include "main.h"
#include "stm32f7xx_hal.h"
#include "servo.h"

extern TIM_HandleTypeDef TimHandle;
TIM_HandleTypeDef TimHandle2;

void Timer_IT_Init() {

	__HAL_RCC_TIM1_CLK_ENABLE();

	TimHandle.Instance               = TIM1;
	TimHandle.Init.Period            = 4000;
	TimHandle.Init.Prescaler         = 54000;
	TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle);
	HAL_TIM_Base_Start_IT(&TimHandle);

	HAL_NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);
}

void TIM1_UP_TIM10_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle);
}

void DriveMeasure_TIM_IT_Init() {
	//Base clock: 108MHz
	__HAL_RCC_TIM2_CLK_ENABLE();

	TimHandle2.Instance               = TIM2;
	TimHandle2.Init.Prescaler         = 54000 - 1; //Now clock speed is 108.000.000 Hz / 100 = 1,08 MHz (Max value is 65535)
	TimHandle2.Init.Period            = 2000 - 1; //Counting to 3000, so at 1,08 MHz the register will overflow in 0,0028 sec.
	TimHandle2.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle2.Init.CounterMode       = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&TimHandle2);
	//HAL_TIM_Base_Start_IT(&TimHandle2);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	TIM2->SR &= ~1;
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle2);
}

//---------------------------------------------------------------

