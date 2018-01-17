#ifndef LCD_GUI_H_
#define LCD_GUI_H_

uint16_t x, y;

uint8_t buttonpress;
uint8_t buttonID;

typedef enum {MAIN, LOAD} Screen;
typedef enum {MOVE_X_POS, MOVE_X_NEG, MOVE_Y_POS, MOVE_Y_NEG, PENUP, PENDOWN, HOME, SDCARD, LOAD_BACK, LOAD_LOAD, LOAD_UP, LOAD_DOWN} ButtonType;
typedef enum {X, Y, Z, ALL} Directions;
typedef enum {NORMAL, HIGHLIGHTED} ButtonMode;

typedef struct Buttons {
	uint16_t x;
	uint16_t y;
	enum {CIRCLE, RECTANGLE} shape;
	uint8_t width;
	uint8_t height;
	uint32_t color;
	uint32_t color_highlighted;
	char text[12];
} Button;

//Function prototypes
void ChangeScreen(Screen CurrentScreen);
void WelcomeScreen();
void MainScreen();
void SDCard_Screen();
void Refresh_Coordinates(float x, float y, int z);
void freshing_lcd();
uint8_t Button_GetID(uint16_t x, uint16_t y);
void Button_Unselect(uint8_t id);
void Button_Run(ButtonType buttonID);
void Button_Draw(ButtonType buttonID, ButtonMode buttonMode);
void Button_Highlight(ButtonType buttonID);
void Scroll_Text();

#endif /* LCD_GUI_H_ */
