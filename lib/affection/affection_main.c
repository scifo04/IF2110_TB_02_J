#include <stdio.h>
#include "affection.h"

int main () {
    int a,b,c;
    Affection Af;
    Affection Af2;
    CreateAffection(&Af);
    int d;
    scanf("%d",&d);
    a = 1;
    b = 3;
    c = 5;
    switch(d) {
        case 1: 
            CreateAffection(&Af2);
            boolean check = true;
            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 20; j++) {
                    if (Af.status[i][j] != Af2.status[i][j]) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    break;
                }
            }
            if (check) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 2:
            convertAffection(&Af,a,b);
            convertAffection(&Af,a,c);
            convertAffection(&Af,b,c);
            if (isFriends_Affection(Af,a,c)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 3:
            if (!isFriends_Affection(Af,a,b)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 4:
            convertAffection(&Af,a,b);
            convertAffection(&Af,a,c);
            convertAffection(&Af,b,c);
            displayAffection(Af);
        case 5:
            convertAffection(&Af,a,b);
            convertAffection(&Af,a,c);
            convertAffection(&Af,b,c);
            int r = countFriends_Affection(Af,a);
            if (r == 2) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
    }
    
    return 0;
}