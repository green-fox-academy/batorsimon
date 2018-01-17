#ifndef GCODE_H_
#define GCODE_H_

typedef struct{
	int G;
	float x;
	float y;
	float z;
	float I;
	float J;
	float R;
	int F;

} codes;

codes code;

void g_code(float temporary);
void m_code(float temporary);
void x_code(float temporary);
void y_code(float temporary);
void z_code(float temporary);
void feed_rate(float temporary);
void x_offset(float temporary); // i
void y_offset(float temporary); // j
void tokenizing(char func_array[]);
void search_codes(char func_array[]);

#endif /* GCODE_H_ */
