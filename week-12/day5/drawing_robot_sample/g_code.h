#ifndef G_CODE_H_INCLUDED
#define G_CODE_H_INCLUDED

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

#endif // G_CODE_H_INCLUDED
