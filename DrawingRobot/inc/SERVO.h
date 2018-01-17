#ifndef SERVO_H_
#define SERVO_H_

//Servo Function prototypes

GPIO_InitTypeDef Servo;
TIM_HandleTypeDef ServoTimHandle;
TIM_OC_InitTypeDef sConfigServo;

void Servo_Init();
void Servo_Timer_Init();
void Z_Axis(int state);

#define pen_down	 0
#define pen_up	 	 1

#endif /* SERVO_H_ */
