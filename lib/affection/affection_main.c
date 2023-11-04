#include <stdio.h>
#include "affection.h"

int main () {
    int a,b,c;
    Affection Af;
    CreateAffection(&Af);
    a = 1;
    b = 3;
    c = 5;
    convertAffection(&Af,a,b);
    convertAffection(&Af,a,c);
    convertAffection(&Af,b,c);
    displayAffection(Af);
    return 0;
}