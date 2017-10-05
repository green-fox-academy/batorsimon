#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int j1 = 10;
	int j2 = 3;
	float j2gyok;
	int j2negyzet;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	j2gyok = sqrt(j2);
	j2negyzet=j2*j2;
    if(j1 > j2gyok && j1 < j2negyzet){
        printf("j1 nagyobb mint j2 negyzetgyoke és kisebb mint j2 négyzete\n");
    } else{
        printf("nem nagyobb\n");
    }

    printf("%d\n", j2);
    printf("%d\n", j2negyzet);
    printf("%f\n", j2gyok);
    return 0;
}
