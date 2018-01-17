#ifndef STEPPER_H_
#define STEPPER_H_

#define x_null		0
#define y_null		0
#define x_max		340
#define y_max 		220
#define PI 3.14

typedef struct {
	float X;
	float Y;
} Position;

Position LastPosition;

void movexy(float x, float y);
void MovedXdY(float dx, float dy);
void home();

void ArcXYIJ(uint8_t G, float X, float Y, float I, float J);
void ArcXYR(uint8_t G, float X, float Y, float R);

// patterns
void CircularPolygon(float x0, float y0, float r, uint8_t n);

typedef enum {X_DIR, Y_DIR} MoveDirection;
typedef enum {CLW, CCLW} RotationDirection;


float absolut_x_position;
float absolut_y_position;

int homed;

#endif /* STEPPER_H_ */
