#ifndef G_CODE_H_INCLUDED
#define G_CODE_H_INCLUDED

typedef struct{
	int G;
	float x;
	float y;
	float Z;
	float I;
	float J;
	float R;
	int F;

} codes;

codes code;

//code = (codes){0,00};

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

typedef struct{
        float g_code;
        float m_cose;
} one_line;

void printel();


#endif // G_CODE_H_INCLUDED
