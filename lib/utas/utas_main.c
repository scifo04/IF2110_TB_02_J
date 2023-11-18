#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

extern int idUtas;

int main(){
    AddressUtas U; CreateUtas(&U);
    DATETIME D; CreateDATETIME(&D);
    Word isiUtas;
    int X;
    scanf("%d", &X);
    switch (X) {
    case 1:
        printf("%d", isEmpty_Utas(U));
        break;
    case 2:
        printf("%d", length(U));
        break;
    default:
        break;
    }
    return 0;
} //gcc -o utas_main utas_main.c utas.c ../datetime/datetime.c ../datetime/time.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c -lm