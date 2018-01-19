#ifndef G_CODE_H_INCLUDED
#define G_CODE_H_INCLUDED

typedef struct{
	int G;      // 1
	float x;    // 2
	float y;    // 3
	float Z;    // 4
	float I;    // 5
	float J;    // 6
	float R;    // 7
	int F;      // 8

} codes;

codes code;

//code = (codes){0};


void tokenizing(char func_array[]);
void search_codes(char func_array[]);
void printel();



void g_code(float temporary);
void m_code(float temporary);
void x_code(float temporary);
void y_code(float temporary);
void z_code(float temporary);
void feed_rate(float temporary);
void x_offset(float temporary); // i
void y_offset(float temporary); // j

typedef struct{
        float g_code;
        float m_cose;
} one_line;



#endif // G_CODE_H_INCLUDED
