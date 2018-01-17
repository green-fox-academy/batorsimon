#include "stm32f7xx_hal.h"
#include "STEPPER.h"
#include "main.h"

TIM_HandleTypeDef TimHandle3;
TIM_HandleTypeDef TimHandle12;
TIM_OC_InitTypeDef sConfig;
extern uint32_t stepp;

void X_Drive_TIM_PWM_Init() {
	//Base clock: 108MHz
	__HAL_RCC_TIM3_CLK_ENABLE();

	TimHandle3.Instance               = TIM3;
	TimHandle3.Init.Prescaler         = 200 - 1; //Now clock speed is 108.000.000 Hz / 100 = 1,08 MHz (Max value is 65535)
	TimHandle3.Init.Period            = 500 - 1; //Counting to 3000, so at 1,08 MHz the register will overflow in 0,0028 sec.
	TimHandle3.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle3.Init.CounterMode       = TIM_COUNTERMODE_UP;

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = 0;

	HAL_TIM_PWM_Init(&TimHandle3);
	HAL_TIM_PWM_ConfigChannel(&TimHandle3, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&TimHandle3, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(TIM3_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

void TIM3_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle3);
}


void Y_Drive_TIM_PWM_Init() {
	//Base clock: 108MHz
	__HAL_RCC_TIM12_CLK_ENABLE();

	TimHandle12.Instance               = TIM12;
	TimHandle12.Init.Prescaler         = 200 - 1; //Now clock speed is 108.000.000 Hz / 100 = 1,08 MHz (Max value is 65535)
	TimHandle12.Init.Period            = 500 - 1; //Counting to 3000, so at 1,08 MHz the reqister will overflow in 0,0028 sec.
	TimHandle12.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
	TimHandle12.Init.CounterMode       = TIM_COUNTERMODE_UP;

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = 0;

	HAL_TIM_PWM_Init(&TimHandle12);
	HAL_TIM_PWM_ConfigChannel(&TimHandle12, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start_IT(&TimHandle12, TIM_CHANNEL_1);

	HAL_NVIC_SetPriority(TIM8_BRK_TIM12_IRQn, 0x0E, 0x00);
	HAL_NVIC_EnableIRQ(TIM8_BRK_TIM12_IRQn);
}

void TIM8_BRK_TIM12_IRQHandler() {
	HAL_TIM_IRQHandler(&TimHandle12);
}


void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	if (stepp > 0) {
		stepp--;

	} else if(stepp == 0){
			TIM3->CCR1 = 0;
			TIM12->CCR1 = 0;

	}

}
