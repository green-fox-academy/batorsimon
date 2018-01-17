#ifndef PWM_H_
#define PWM_H_

//Function prototypes
void X_Drive_TIM_PWM_Init();
void TIM3_IRQHandler();

void Y_Drive_TIM_PWM_Init();
void TIM8_BRK_TIM12_IRQHandler();

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);

#endif /* PWM_H_ */
