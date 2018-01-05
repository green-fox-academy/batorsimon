#include <stdio.h>
#include <stdlib.h>

#include "g_code.h"
#include "read_from_file.h"

int main()
{
    //read_complete_file();

    char *p;
    for(int i = 0; i < couting_lines(); i++){
        p = read_file_line_by_line();
        tokenizing(p);
    }

    //char probe[500] = "G03 X29.297604 Y20.946643 Z-1.000000 I-1.029490 J-1.472092 F200.000000";
    //printf("probe: %s\n", probe);
    //tokenizing(probe);

    return 0;
}
