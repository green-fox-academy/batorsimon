/*
 * Drawing Robot Project
 * ---------------------
 * Started 2018.01.03.
 *
 * CNC Shield Pinouts to STM32F7-DISCO (Arduino compatible)
 * A0 - Reset/Abort
 * A1 - Feed Hold
 * A2 - Cycle start / Resume
 * A3 - N/A (Coolant enable)
 * A4 - N/A
 * A5 - N/A
 *
 * D0 - RX
 * D1 - TX
 * D2 - Step X
 * D3 - Step Y
 * D4 - Step Z
 * D5 - Dir X
 * D6 - Dir Y
 * D7 - Dir Z
 * D8 - Stepper enable/disable
 * D9 - Limit Switch X
 * D10 - Limit Switch Y
 * D11 - N/A (Limit Switch Z)
 * D12 - N/A (Spindle enable)
 * D13 - N/A (Spindle direction)
 */

#include "stm32f7xx_hal.h"
#include "read_from_file.h"

#include <string.h>
#include <stdio.h>

#include "main.h"
#include "DEF.h"
#include "GPIO.h"
#include "tim.h"
#include "PWM.h"
#include "STEPPER.h"
#include "UART.h"
#include "servo.h"
#include "FLASH.h"
#include "LCD_GUI.h"
#include "logo.h"
#include "margins.h"
#include "GCODE.h"

//Global variables

TIM_HandleTypeDef TimHandle;
GPIO_InitTypeDef marginsw;

int x_zero_reached = 0;	// x sensor to D9 pin
int y_zero_reached = 0;	// y sensor to D10 pin
int z;

//Stepper variables
GPIO_InitTypeDef Stepper;
uint16_t d1, d2;
uint32_t stepp = 0;



int main(void) {
	//Hardware config and init...
	STM32F7_DISCOVERY_HW_Init();

	// LCD INIT
	WelcomeScreen();
	MainScreen();

	//Margin switch init...
	marginsw_init();

	//Start UART...
	UART_Config(&UartHandle);
	HAL_UART_Init(&UartHandle);
	HAL_UART_Receive_IT(&UartHandle, &UART_IT_Data, 1);

	//Init Servo
	Servo_Init();
	Servo_Timer_Init();

	// Logo
	Logo();

	//Stepper_Move();
		//Enable stepper motors
		GPIO_Init(Stepper_ALL_ENABLE_PORT, Stepper_ALL_ENABLE_PIN);       //GPIO_Init(Stepper_X_STEP_PORT, Stepper_X_STEP_PIN);
		GPIO_PWM_Init(Stepper_X_STEP_PORT, Stepper_X_STEP_PIN, GPIO_AF2_TIM3);
		GPIO_Init(Stepper_X_DIR_PORT, Stepper_X_DIR_PIN);            //GPIO_Init(Stepper_Y_STEP_PORT, Stepper_Y_STEP_PIN);
		GPIO_PWM_Init(Stepper_Y_STEP_PORT, Stepper_Y_STEP_PIN, GPIO_AF9_TIM12);
		GPIO_Init(Stepper_Y_DIR_PORT, Stepper_Y_DIR_PIN);

		//Init timer interrupt on stepper motors step pins
		//X_Drive_TIM_IT_Init();
		//Y_Drive_TIM_IT_Init();
		X_Drive_TIM_PWM_Init();
		Y_Drive_TIM_PWM_Init();
		DriveMeasure_TIM_IT_Init();

		//Save_to_Flash((uint16_t)3200, (uint16_t)77);
		//HAL_Delay(10);
		//Read_from_Flash();

		homed = 0;   // can not move until its not homed ( homed = 0; )
		// set it to 1 if you want to run a test program without homing

		//home();

		//CircularPolygon(100, 100, 40, 360);

		/* relativ
		MovedXdY(50, 5);
		MovedXdY(-10, 32);
		MovedXdY(-40, -37);        */

		/* abszolut:  in MovedXdY(0, 0);
		movexy(50, 5);
		movexy(40, 37);
		movexy(0, 0);    */


	while (1) {

			/*tokenizing(G_Code_Buffer);
			HAL_Delay(1000);*/
			freshing_lcd();


	//read_complete_file();

	}

}
