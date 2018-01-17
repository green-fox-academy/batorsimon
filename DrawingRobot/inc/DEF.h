/*
 * Drawing Robot
 * -------------
 * This file contains constant definitions
 */

#ifndef DEF_H_
#define DEF_H_

//This pin enables all stepper motors connected to CNC shield
// Set pin to low (0) to enable, or high (1) to disable
#define Stepper_ALL_ENABLE_PORT GPIOI
#define Stepper_ALL_ENABLE_PIN GPIO_PIN_2

//Stepper motor connections for X direction (marked as Y on shield)
#define Stepper_X_STEP_PORT GPIOB
#define Stepper_X_STEP_PIN GPIO_PIN_4
#define Stepper_X_DIR_PORT GPIOH
#define Stepper_X_DIR_PIN GPIO_PIN_6

//Stepper motor connections for Y direction (marked as A on shield)
#define Stepper_Y_STEP_PORT GPIOB
#define Stepper_Y_STEP_PIN GPIO_PIN_14
#define Stepper_Y_DIR_PORT GPIOI
#define Stepper_Y_DIR_PIN GPIO_PIN_1

//Servo motor connection for Z liftups
//#define
//#define

//Motor resolution
#define Step_per_mm 100

//Limit switches for homing
#define LimitSwitch_X_PORT GPIOA
#define LimitSwitch_X_PIN GPIO_PIN_15
#define LimitSwitch_Y_PORT GPIOA
#define LimitSwitch_Y_PIN GPIO_PIN_8

#endif /* DEF_H_ */
