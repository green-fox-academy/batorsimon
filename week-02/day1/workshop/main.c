#include <stdio.h>
#include <stdlib.h>

// .h security -t l�trehozok �s abba teszem azt ami titkos ha nem t�lt�m fel csak .c f�jlt akkor nem l�tj�k pl a jelszavam stb

// z�ldek: header f�jlok
//l�trehozhatok �n is defineokat
#define  MYNAME "bator"
#define MYAGE 23
// define konstans v�lltozokat defini�lunk
//el�ssz�r ezt kapja meg a preprocesszor

#define true 1
#define false 0

// f�ggv�nyek �rtelmes tartom�ny�nak meghat�roz�sa!! fontos ne halljon meg a processzor!! pl 0-val nem osztunk
//function-ok
void start_screen();
int addition(int num1, int num2);
int multiply(int num3);
int is_bigger_then_10(int num4);
void use_static_var();

int main()
{
    start_screen();
    printf("%d\n", addition(7, 3));
    printf("%d\n", multiply(addition(3, 7)));

    if (is_bigger_then_10(8))
        printf("your input was bigger than 10!\n");
    else
        printf("your input was smaller than 10!");



    use_static_var();
    use_static_var();
    use_static_var();
    use_static_var();
    use_static_var();


    printf("my name is %s, and I am %d years old\n", MYNAME, MYAGE);

    if (true)
        printf("this looks like boolen!\n");



    return 0;


}

void start_screen()
{
    printf("hello user\n");
    printf("this is a program\n");
    printf("have fun!\n");
}

int addition(int num1, int num2)
{
    return num1+num2;
}

int multiply(int num 3)
{
    return num3 * 5;
}

int is_bigger_then_10(int num4)
{
    if (num4 <= 10)
        return 0;
    else
        return 1;
}

void use_static_var()
{
    int a = 10;
    static sa = 20;

    a += 5;
    sa += 5;

    printf("a is %d\n", a);
    printf("static a is %d\n", sa);

    // int a mindig l�trehozodik, a static nem
    // static �rt�ke �lland� marad nem �rja f�l�l a deklar�l�s a sima int meg igen
}

