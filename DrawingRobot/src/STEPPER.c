#include "stm32f7xx_hal.h"
#include "STEPPER.h"
#include "main.h"
#include "margins.h"
#include "servo.h"
#include "LCD_GUI.h"
#include  <math.h>

extern uint32_t stepp;
extern int z;

void home() {

	if(homed == 1){
		printf("Already homed!\n");
	}  else {
	// you only need to home once

		// pen not draw something messy
		Z_Axis(pen_up);

			// axis x home point
			while(!x_zero_reached) {
				int x = 350;
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 0);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 0);
				TIM3->CCR1 = 50;
				TIM12->CCR1 = 50;
				stepp = 200 * x;
			}

			if(x_zero_reached == 1) {
				TIM3->CCR1 = 0;
				TIM12->CCR1 = 0;
			}

			// axis y home point
			while(!y_zero_reached) {
				int y = 230;
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 1);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 0);
				TIM3->CCR1 = 50;
				TIM12->CCR1 = 50;
				stepp = 200 * y;
			}

			if(y_zero_reached == 1){
					TIM3->CCR1 = 0;
					TIM12->CCR1 = 0;
				}

			if(y_zero_reached == 1 && x_zero_reached == 1) {
				printf("Homed!!\n");
				absolut_x_position = 0;
				absolut_y_position =0;
				homed = 1;
				printf("absolut_x_position: %.2g, absolut_y_position: %.2g \n", absolut_x_position, absolut_y_position);
				Refresh_Coordinates(absolut_x_position, absolut_y_position, z);

			}

	}

}

void movexy(float x, float y){
	MovedXdY(x -LastPosition.X, y- LastPosition.Y );

	LastPosition.X = x;
	LastPosition.X = y;

}
void MovedXdY(float dx, float dy) {

	x_zero_reached = 0;
	y_zero_reached = 0;

		if(homed == 0){
			// can not move until it is not homed
			dx=0;
			dy=0;

		} else {

		    absolut_x_position = dx +absolut_x_position;
			absolut_y_position = dy + absolut_y_position;


			if(absolut_x_position < 0) {
					dx = 0;
					absolut_y_position = 0;
					x_zero_reached = 1;
				}

			if(absolut_y_position < 0 ) {
				dy = 0;
				absolut_y_position = 0;
				y_zero_reached =1;
			}

				if(absolut_y_position > y_max) {
					absolut_y_position = y_max;
					dy = 0;
				}

				if(absolut_x_position > x_max) {
						absolut_x_position = x_max;
						dx = 0;
				}


				if(x_zero_reached == 1 ) {
								TIM3->CCR1 = 0;
								TIM12->CCR1 = 0;
							}

				if(y_zero_reached == 1 ) {
								TIM3->CCR1 = 0;
								TIM12->CCR1 = 0;
							}


			//Do not start new move function before the previous function did not finished (still counting down (if the motor moving))
			while (stepp != 0) {}

			//If no moving don't bother
			if (dx == 0 && dy == 0) {return;}

			//Decide which motor turns more -> that will be the faster (with fixed constant speed)
			if (fabs(dx + dy) >= fabs(-dx + dy)) {	//If A motor turning more belt, than...
				TIM3->ARR = 200;					//...set motor A to the fixed fast speed...
				TIM3->CNT = 0;
				TIM12->ARR = -dx + dy != 0 ? (uint32_t)( 200 * fabs((dx + dy) / (-dx + dy)) ) : 65535;
				TIM12->CNT = 0;						//...and set motor B proportionally slower, or to "stop speed"
			} else {
				TIM12->ARR = 200;					//If B motor turning more, than set that to the fixed constant speed...
				TIM12->CNT = 0;
				TIM3->ARR = dx + dy != 0 ? (uint32_t)( 200 * fabs((-dx + dy) / (dx + dy)) ) : 65535;
				TIM3->CNT = 0;						//...and let A motor be slower proportionally or "stopped speed"
			}

			//Stepper motor counter generation: no of steps both motor will do
			//This value of cnt will be deducted at each PWM_pulsecallback (called by both motor timers)
			stepp = 100 * fabs(dx + dy) + 100 * fabs(-dx + dy); //Max theoretical counter value = 100*(320mm + 220mm)=54000 -> 16bit ok

			//Start motors:
			//Set A stepper DIR
			if (dx + dy == 0) {								//If head movement +135° or -45° -> A motor standing
				TIM3->CCR1 = 0;
			} else if (dx + dy > 0) {						//if sum of head movement coordinates are positive, it means head
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 1);	//gets further from motor A -> A stepper turning positive (gives belt)
				TIM3->CCR1 = 50;							//Start motor
			} else { //< 0									//If the sum of head movement coordinates are negative, it means head
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 0);	//gets closet to motor A -> A stepper turning negative (pulls belt)
				TIM3->CCR1 = 50;							//Start motor
			}

			//Set B stepper DIR
			if (-dx + dy == 0) {							//If head movement +45° or +225° -> B motor standing
				TIM12->CCR1 = 0;
			} else if (-dx + dy > 0) {
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 0);
				TIM12->CCR1 = 50;
			} else { //< 0
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 1);
				TIM12->CCR1 = 50;
			}

			printf("absolut_x_position: %.2g, absolut_y_position: %.2g \n", absolut_x_position, absolut_y_position);
		Refresh_Coordinates(absolut_x_position, absolut_y_position, z);

	}

}



void CircularPolygon(float x0, float y0, float r, uint8_t n) {
	float x, y;
	for (uint8_t i = 0; i <= n; ++i) {
		movexy (
				x = x0 - r * cos((double)(i * 360 / n * PI / 180)),
				y = y0 + r * sin((double)(i * 360 / n * PI / 180))
		);
		printf("%g - %g\n", x, y);
	}
}

//---Drawing an arc according to Gcode format: G02/G03 X34.5 Y22.1 I10 J23----------------------------------
//---G02 CLW - clockwise direction
//---G03 CCLW - counter clockwise direction
//---X, Y - ending point (not necessary a point of the circle, defines an angle)
//---I, J - center of circle/arc relative to the current position
void ArcXYIJ(uint8_t G, float X, float Y, float I, float J) {
	float x, y;
	float start_x = LastPosition.X;
	float start_y = LastPosition.Y;

	//Get radius squared from the last position and the origin(I,J)
	//float R_sq = (LastPosition.X - I) * (LastPosition.X - I) + (LastPosition.Y - J) * (LastPosition.Y - J);
	float R_sq = I * I + J * J;
	printf("R = %g\n", sqrt(R_sq));

	//Get distance (squared) of end coordinate from origin
	//float RXY_sq = (X - I) * (X - I) + (Y - J) * (Y - J);
	float RXY_sq = (LastPosition.X + I - X) * (LastPosition.X + I - X) + (LastPosition.Y + J - Y) * (LastPosition.Y + J - Y);
	printf("RXY = %g\n", sqrt(RXY_sq));

	//Calculate third side (squared) of the triangle from two point coordinates: LP & X,Y
	float c_sq = (LastPosition.X - X) * (LastPosition.X - X) + (LastPosition.Y - Y) * (LastPosition.Y - Y);
	printf("c = %g\n", sqrt(c_sq));

	//Calculate angle (law of cosine) (radian -> angle)
	float alpha = acos( (R_sq + RXY_sq - c_sq) / (2 * sqrt(R_sq) * sqrt(RXY_sq)) ) * 180 / PI;
	printf("alpha = %g\n", alpha);

	//Generating vector cross product for determine the angle of start/stop vectors
	// vector_a = [-I,-J,0]; vector_b = [X-I,Y-J,0]; -> axb = [0,0,X*J-Y*J];
	//axb pointing upwards (+) if ...
	//axb not zero!
	float z = X * J - Y * I;
	//CLW rotation direction
	if (G == 2 && z > 0) {alpha = 360 - alpha;}
	//else if (G == 2 && z < 0) {alpha = alpha;}
	//CCLW rotation direction
	if (G == 3 && z < 0) {alpha = 360 - alpha;}
	//else if (G == 3 && z > 0) {alpha = alpha;}

	//Calculate elementary step angle eg: 63.45° -> 63x piece = 1 step angle is 63.45/63°
	float step_angle;
	if (G == 2) {step_angle = -alpha / ( (uint16_t)alpha );} 	//CLW
	else 		{step_angle =  alpha / ( (uint16_t)alpha );}	//CCLW

	for (uint16_t i = 1; i <= (uint16_t)alpha; ++i) {
		movexy(
				//with vector transformation: v' = T * v
				//x = I - ( (I - LastPosition.X) * cos(step_angle * PI / 180) - (J - LastPosition.Y) * sin(step_angle * PI / 180) ),
				//y = J - ( (I - LastPosition.X) * sin(step_angle * PI / 180) + (J - LastPosition.Y) * cos(step_angle * PI / 180) )
				x = start_x + I - I * cos(step_angle * i * PI / 180) + J * sin(step_angle * i * PI / 180),
				y = start_y + J - I * sin(step_angle * i * PI / 180) - J * cos(step_angle * i * PI / 180)
		);
		printf("%g - %g\n", x, y);
	}
}

void ArcXYR(uint8_t G, float X, float Y, float R) {
	//angle
	float alpha = acos(1 - (X*X + Y*Y)/(2*R*R)) * PI / 180;

	float i = X*X + Y*Y;
	float j = 2*X;

	float a = j*j + 4*Y*Y;
	float b = -2*i*j;
	float c = i*i - 4*Y*Y*R*R;

	float I1 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
	float I2 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
	float J1 = sqrt(R*R - I1*I1);
	float J2 = sqrt(R*R - I2*I2);

	//Cross products
	float z1 = X*J1 - Y*I1;
	float z2 = X*J2 - Y*I2;

	if (G == 2) {alpha = -alpha / ( (uint16_t)alpha );} 	//CLW
	else 		{alpha =  alpha / ( (uint16_t)alpha );}	//CCLW

}
