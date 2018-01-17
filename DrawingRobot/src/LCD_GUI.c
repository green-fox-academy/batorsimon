/*
 * Drawing Robot
 * -------------
 * This file contains the LCD HMI (GUI) functions
 */
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "LCD_GUI.h"
#include "STEPPER.h"
#include "main.h"

extern int z;

uint8_t Buttons_on_Screen_startIndex = 0;
uint8_t Buttons_on_Screen_endIndex = 7;

TS_StateTypeDef TS_State;

Button LCD_Buttons[12] = {
	//Main screen buttons
	{410, 120, CIRCLE, 60, 60, LCD_COLOR_RED, LCD_COLOR_DARKRED, "+X"},
	{250, 120, CIRCLE, 60, 60, LCD_COLOR_RED, LCD_COLOR_DARKRED, "-X"},
	{330, 50, CIRCLE, 60, 60, LCD_COLOR_RED, LCD_COLOR_DARKRED, "+Y"},
	{330, 190, CIRCLE, 60, 60, LCD_COLOR_RED, LCD_COLOR_DARKRED, "-Y"},
	{140, 50, RECTANGLE, 46, 46, LCD_COLOR_BLUE, LCD_COLOR_DARKBLUE, "UP"},
	{240, 50, RECTANGLE, 46, 46, LCD_COLOR_BLUE, LCD_COLOR_DARKBLUE, "DOWN"},
	{10, 200, RECTANGLE, 100, 60, LCD_COLOR_GREEN, LCD_COLOR_DARKGREEN, "HOME"},
	{160, 200, RECTANGLE, 100, 40, LCD_COLOR_GRAY, LCD_COLOR_DARKGRAY, "SD card"},
	//Load (SC Card) screen buttons
	{10, 10, RECTANGLE, 100, 40, LCD_COLOR_GRAY, LCD_COLOR_DARKGRAY, "Back"},
	{10, 70, RECTANGLE, 100, 40, LCD_COLOR_RED, LCD_COLOR_DARKRED, "Load&Run"},
	{50, 130, CIRCLE, 50, 50, LCD_COLOR_CYAN, LCD_COLOR_DARKCYAN, "UP"},
	{50, 210, CIRCLE, 50, 50, LCD_COLOR_CYAN, LCD_COLOR_DARKCYAN, "DW"}
};

const char DummyText[6][15] = {"Text.txt", "hello.txt", "circle.txt", "triangle.txt", "zoli.txt", "blabla.txt"};

void ChangeScreen(Screen CurrentScreen) {
	if (CurrentScreen == MAIN) {
		Buttons_on_Screen_startIndex = 0;
		Buttons_on_Screen_endIndex = 7;
	} else if (CurrentScreen == LOAD) {
		Buttons_on_Screen_startIndex = 8;
		Buttons_on_Screen_endIndex = 11;
	}
}

void WelcomeScreen() {

	BSP_LCD_Init();
	BSP_LCD_DisplayOn();

	/* Initialize the LCD Layers */
	BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS+(480*272*4));
	//BSP_LCD_LayerRgb565Init(0, LCD_FB_START_ADDRESS);
	//BSP_LCD_LayerRgb565Init(1, LCD_FB_START_ADDRESS+(480*272*4));

	//Set LCD first layer & clear the LCD
	BSP_LCD_SelectLayer(0);
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	//Set LCD second layer & clear the LCD
	BSP_LCD_SelectLayer(1);
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	//Load Sc card screen onto the second layer
	SDCard_Screen();

	//Set first layer & activate
	BSP_LCD_SelectLayer(0);
	BSP_LCD_SetLayerVisible(0, ENABLE);
	BSP_LCD_SetLayerVisible(1, DISABLE);

	/* Set the LCD Text Color */
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(0, 120, (uint8_t*)"DrawingRobot", CENTER_MODE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(0, 140, (uint8_t*)"made by Team Kornubit, 2018", CENTER_MODE);
	HAL_Delay(500);
}

void MainScreen() {
	//Clear screen
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	/* Display LCD messages */
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_DisplayStringAt(0, 5, (uint8_t*)"DrawingRobot CNC Controller", CENTER_MODE);

	BSP_LCD_DrawHLine(0, 35, 480);

	//Coordinates
	BSP_LCD_DisplayStringAt(0, 70, (uint8_t*)"X -----", LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 110, (uint8_t*)"Y -----", LEFT_MODE);
	BSP_LCD_DisplayStringAt(0, 150, (uint8_t*)"Z -----", LEFT_MODE);

	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(0, 45, (uint8_t*)"Coordinates [mm]", LEFT_MODE);
	BSP_LCD_DisplayStringAt(200, 65, (uint8_t*)"Pen", LEFT_MODE);
	BSP_LCD_DisplayStringAt(0 , 45, (uint8_t*)"Manual move", RIGHT_MODE);

	BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() - 12, (uint8_t*)"Team Kornubit - 2018", CENTER_MODE);

	Button_Draw(MOVE_X_POS, NORMAL);
	Button_Draw(MOVE_X_NEG, NORMAL);
	Button_Draw(MOVE_Y_POS, NORMAL);
	Button_Draw(MOVE_Y_NEG, NORMAL);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawHLine(330, 150, 60);
	BSP_LCD_DrawVLine(360, 130, 40);

	Button_Draw(PENUP, NORMAL);
	Button_Draw(PENDOWN, NORMAL);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawHLine(191, 100, 45);
	BSP_LCD_DrawHLine(191, 46, 45);

	Button_Draw(HOME, NORMAL);

	Button_Draw(SDCARD, NORMAL);

	ChangeScreen(MAIN);

	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
}

void SDCard_Screen() {
	//Print header
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(0, 5, (uint8_t*)"Load G-Code file", RIGHT_MODE);
	BSP_LCD_DrawHLine(125, 35, 355);

	//Draw buttons
	Button_Draw(LOAD_BACK, NORMAL);
	Button_Draw(LOAD_LOAD, NORMAL);
	Button_Draw(LOAD_UP, NORMAL);
	Button_Draw(LOAD_DOWN, NORMAL);

	//Draw frame
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DrawRect(125, 40, 350, 230);

	BSP_LCD_SetFont(&Font12);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayStringAt(60, 140, (uint8_t*)"No SD-Card inserted", CENTER_MODE);

	//Scroll_Text();
}

void Refresh_Coordinates(float x, float y, int z) {

	if( y < 0 ) {
			y = 0;
	}

	if( x < 0 ) {
		x = 0;
	}

	if(y > y_max) {
		y = y_max;
	}

	if(x > x_max) {
		x = x_max;
	}


	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

	char text[30];

	sprintf(text, " %05.2g", x);
	BSP_LCD_DisplayStringAt(32, 70, (uint8_t *)text, LEFT_MODE);

	sprintf(text, " %05.2g", y);
	BSP_LCD_DisplayStringAt(32, 110,(uint32_t *)text, LEFT_MODE);

	sprintf(text, " %05d", z);
	BSP_LCD_DisplayStringAt(32, 150, (uint32_t *)text, LEFT_MODE);

}


void freshing_lcd() {

	//Polling touch screen status
			BSP_TS_GetState(&TS_State);
			//If the screen has been touched...
			if(TS_State.touchDetected) {

				// Get X and Y position of the touch
				x = TS_State.touchX[0];
				y = TS_State.touchY[0];

				//Get pressing information according to coordinates and get button id if we pressed a button
				buttonID = Button_GetID(x, y);

				//If a button is just pressed now... (buttonpress was 0 until now)
				if (buttonID != 255 && buttonpress == 0) {
					buttonpress = 1;						//Set state to pressed
					Button_Highlight(buttonID);				//Highlight it graphically (only once)
				}

				//If an empty area is pressed, but a button was also pressed before (slipped off the button)
				if (buttonID == 255 && buttonpress == 1) {	//unselect all buttons (b'cause don't know which button the finger slipped off)
					for (int i = Buttons_on_Screen_startIndex; i <= Buttons_on_Screen_endIndex; ++i) {
						Button_Unselect(i);
					}
					buttonpress = 0;						//No button is pressed now
				}

			 //...if the screen has been released (not touched)
			 } else {								//If there's no pressing
				 if (buttonpress == 1) {			//If the button was pressed and just released
					 Button_Unselect(buttonID);		//Unhighlight the button graphically
					 Button_Run(buttonID);			//Execute button task
					 buttonpress = 0;				//Set state=not pressed
				 }
			 }

}

uint8_t Button_GetID(uint16_t x, uint16_t y) {
	for (int i = Buttons_on_Screen_startIndex; i <= Buttons_on_Screen_endIndex; ++i) {
		if (x > LCD_Buttons[i].x && x < LCD_Buttons[i].x + LCD_Buttons[i].width && y > LCD_Buttons[i].y && y < LCD_Buttons[i].y + LCD_Buttons[i].height) {
			return i;
		}
	}
	return 255;
}

void Button_Highlight(ButtonType buttonID) {
	Button_Draw(buttonID, HIGHLIGHTED);
	switch (buttonID) {
			case MOVE_X_POS:
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 1);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 1);
				TIM3->ARR = 250 - 1;
				TIM3->CCR1 = 50;
				TIM12->ARR = 250 - 1;
				TIM12->CCR1 = 50;
				//Refresh_Coordinates(absolut_x_position, absolut_y_position++, z);
				break;
			case MOVE_X_NEG:
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 0);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 0);
				TIM3->ARR = 250 - 1;
				TIM3->CCR1 = 50;
				TIM12->ARR = 250 - 1;
				TIM12->CCR1 = 50;
				//Refresh_Coordinates(X, --x_cnt);
				break;
			case MOVE_Y_POS:
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 0);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 1);
				TIM3->ARR = 250 - 1;
				TIM3->CCR1 = 50;
				TIM12->ARR = 250 - 1;
				TIM12->CCR1 = 50;
				//Refresh_Coordinates(Y, ++y_cnt);
				break;
			case MOVE_Y_NEG:
				HAL_GPIO_WritePin(GPIOI, GPIO_PIN_1, 1);
				HAL_GPIO_WritePin(GPIOH, GPIO_PIN_6, 0);
				TIM3->ARR = 250 - 1;
				TIM3->CCR1 = 50;
				TIM12->ARR = 250 - 1;
				TIM12->CCR1 = 50;
				//Refresh_Coordinates(Y, --y_cnt);
				break;
	}
}

void Button_Unselect(ButtonType buttonID) {	//Button color restore after release
	Button_Draw(buttonID, NORMAL);
	if (buttonID <= 3) {
			TIM3->CCR1 = 0;
			TIM12->CCR1 = 0;
	}
}

void Button_Run(ButtonType buttonID) {
	switch (buttonID) {
		case PENUP:
			//Refresh_Coordinates(Z, ++z_cnt);
			break;
		case PENDOWN:
			//Refresh_Coordinates(Z, --z_cnt);
			break;
		case HOME:
			home();
			//Refresh_Coordinates(ALL, x_cnt = y_cnt = z_cnt = 0);
			break;
		case SDCARD:
			for (int i = 2; i <= 272; i+=2) {
				BSP_LCD_SetLayerAddress(0, LCD_FB_START_ADDRESS+(480*i*4));
				if (i > 0 && i < 272-50) HAL_Delay(3);
				else HAL_Delay(20);
			}
			BSP_LCD_SetLayerAddress_NoReload(0, LCD_FB_START_ADDRESS);

			BSP_LCD_SetLayerVisible_NoReload(0, DISABLE);
			BSP_LCD_SetLayerVisible_NoReload(1, ENABLE);
			BSP_LCD_SelectLayer(1);

			ChangeScreen(LOAD);
			break;
		case LOAD_BACK:
			for (int i = 270; i >= 0; i-=2) {
				BSP_LCD_SetLayerAddress(1, LCD_FB_START_ADDRESS+(480*i*4));
				if (i < 272 && i > 0+50) HAL_Delay(3);
				else HAL_Delay(20);
			}
			BSP_LCD_SetLayerAddress_NoReload(1, LCD_FB_START_ADDRESS+(480*272*4));

			BSP_LCD_SetLayerVisible_NoReload(1, DISABLE);
			BSP_LCD_SetLayerVisible_NoReload(0, ENABLE);
			BSP_LCD_SelectLayer(0);

			ChangeScreen(MAIN);
			break;
	}
}

void Button_Draw(ButtonType buttonID, ButtonMode buttonMode) {
	BSP_LCD_SetFont(&Font16);

	switch (buttonMode) {
	case NORMAL:      BSP_LCD_SetTextColor(LCD_Buttons[buttonID].color);
					  BSP_LCD_SetBackColor(LCD_Buttons[buttonID].color);
				      break;
	case HIGHLIGHTED: BSP_LCD_SetTextColor(LCD_Buttons[buttonID].color_highlighted);
					  BSP_LCD_SetBackColor(LCD_Buttons[buttonID].color_highlighted);
					  break;
	}

	switch (LCD_Buttons[buttonID].shape) {
	case CIRCLE:    BSP_LCD_FillCircle(LCD_Buttons[buttonID].x + LCD_Buttons[buttonID].width / 2, LCD_Buttons[buttonID].y + LCD_Buttons[buttonID].width / 2, LCD_Buttons[buttonID].width / 2);
				    BSP_LCD_DrawCircle(LCD_Buttons[buttonID].x + LCD_Buttons[buttonID].width / 2, LCD_Buttons[buttonID].y + LCD_Buttons[buttonID].width / 2, LCD_Buttons[buttonID].width / 2 + 6);

				    BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
				 	BSP_LCD_DisplayStringAt(LCD_Buttons[buttonID].x + LCD_Buttons[buttonID].width / 2 - 12, LCD_Buttons[buttonID].y + LCD_Buttons[buttonID].width / 2 - 6, (uint8_t *)LCD_Buttons[buttonID].text, LEFT_MODE);
				    break;
	case RECTANGLE: BSP_LCD_FillRect(LCD_Buttons[buttonID].x, LCD_Buttons[buttonID].y, LCD_Buttons[buttonID].width, LCD_Buttons[buttonID].height);
					BSP_LCD_DrawRect(LCD_Buttons[buttonID].x - 4, LCD_Buttons[buttonID].y - 4, LCD_Buttons[buttonID].width + 8, LCD_Buttons[buttonID].height + 8);

					BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
					BSP_LCD_DisplayStringAt(LCD_Buttons[buttonID].x + 2, LCD_Buttons[buttonID].y + 2, (uint8_t *)LCD_Buttons[buttonID].text, LEFT_MODE);
					break;
	}
}

void Scroll_Text() {
//	125, 40, 350, 230

	uint32_t sdram_Buffer[6] = {0xffffffff, 0xffffffff,0xffffffff, 0xffffffff,0xffffffff, 0xffffffff};

	BSP_LCD_SetFont(&Font16); //Font16 -> 24 pixel tall ???
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);

 	BSP_LCD_DisplayStringAt(125+5, 254, (uint8_t *)DummyText[0], LEFT_MODE);

 	BSP_SDRAM_WriteData(LCD_FB_START_ADDRESS+(480*272*4), sdram_Buffer, (uint32_t)20);
}
