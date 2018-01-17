#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include "main.h"

//GPIO pin initialization function to save space
void GPIO_Init(GPIO_TypeDef* _GPIOx, uint16_t _GPIO_PIN_x) {
	GPIO_InitTypeDef Pins;

	if (_GPIOx == GPIOB) {__HAL_RCC_GPIOB_CLK_ENABLE();}
	else if (_GPIOx == GPIOB) {__HAL_RCC_GPIOB_CLK_ENABLE();}
	else if (_GPIOx == GPIOH) {__HAL_RCC_GPIOH_CLK_ENABLE();}
	else if (_GPIOx == GPIOI) {__HAL_RCC_GPIOI_CLK_ENABLE();}

	Pins.Pin = _GPIO_PIN_x;
	Pins.Mode = GPIO_MODE_OUTPUT_PP;
	Pins.Pull = GPIO_NOPULL;
	Pins.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(_GPIOx, &Pins);

	//After initialization set pin to low (0 == GPIO_PIN_RESET) by default
	HAL_GPIO_WritePin(_GPIOx, _GPIO_PIN_x, 0);
}
//------------------------------------------------------------------
void GPIO_PWM_Init(GPIO_TypeDef* _GPIOx, uint16_t _GPIO_PIN_x, uint8_t _GPIO_AFx_TIMy) {
	GPIO_InitTypeDef Pins;

	__HAL_RCC_GPIOB_CLK_ENABLE();

	Pins.Pin = _GPIO_PIN_x;
	Pins.Mode = GPIO_MODE_AF_PP;
	Pins.Pull = GPIO_NOPULL;
	Pins.Speed = GPIO_SPEED_LOW;
	Pins.Alternate = _GPIO_AFx_TIMy;

	HAL_GPIO_Init(_GPIOx, &Pins);

	//After initialization set pin to low (0 == GPIO_PIN_RESET) by default
	HAL_GPIO_WritePin(_GPIOx, _GPIO_PIN_x, 0);
}
