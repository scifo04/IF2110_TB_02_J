#include <stdio.h>
#include <stdlib.h>
#include "../utas.h"

extern int idUtas;

int main(){
    AddressUtas U; CreateUtas(&U);
    DATETIME D; Day(D) = 31; Month(D) = 10; Year(D) = 2023; Hour(Time(D)) = 23; Minute(Time(D)) = 59; Second(Time(D)) = 59;
    Word Author; Author.TabWord[0] = 'J'; Author.TabWord[1] = 'o'; Author.TabWord[2] = 'e'; Author.Length = 3;
    STARTWORD();
    int X = Akuisisi_First_Integer(currentWord);
    switch (X) {
    case 1: // alokasi
        STARTWORD();
        AddressUtas tes = newUtas(D, currentWord);
        TulisDATETIME(waktuUtas(tes));
        printf("\n");
        printWord(isiTwitUtas(tes));
        printf("\n");
        printf("%d\n", (Sambungan(tes) == NULL));
        break;
    case 2: // tes kosong
        printf("%d\n", isEmpty_Utas(U));
        break;
    case 3: // insertAtUtas
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 1);
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 1);
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 3);
        printWord(isiTwitUtas(U));
        printf("\n");
        printWord(isiTwitUtas(Sambungan(U)));
        printf("\n");
        printWord(isiTwitUtas(Sambungan(Sambungan(U))));
        printf("\n");
        break;
    case 4: // insertLastUtas
        STARTWORD();
        insertLastUtas(&U, D, currentWord);
        STARTWORD();
        insertLastUtas(&U, D, currentWord);
        printWord(isiTwitUtas(U));
        printf("\n");
        printWord(isiTwitUtas(Sambungan(U)));
        printf("\n");
        break;
    case 5: // deleteAtUtas
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 1);
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 2);
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 3);
        deleteAtUtas(&U, 3);
        printWord(isiTwitUtas(U));
        printf("\n");
        printWord(isiTwitUtas(Sambungan(U)));
        printf("\n");
        deleteAtUtas(&U, 1);
        printWord(isiTwitUtas(U));
        printf("\n");
        deleteAtUtas(&U, 1);
        printf("%d\n", (U == NULL));
        break;
    case 6: // tes panjang
        printf("%d", lengthUtas(U));
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 1);
        printf("%d", lengthUtas(U));
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 1);
        printf("%d", lengthUtas(U));
        STARTWORD();
        insertAtUtas(&U, D, currentWord, 3);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 3);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 1);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 1);
        printf("%d\n", lengthUtas(U));
        break;
    case 7: // cetak Utas
        STARTWORD();
        insertLastUtas(&U, D, currentWord);
        STARTWORD();
        insertLastUtas(&U, D, currentWord);
        cetakUtas(U, Author);
        break;
    default:
        break;
    }
    return 0;
} //gcc -o utas_main utas_main.c ../utas.c ../../datetime/datetime.c ../../datetime/time.c ../../wordmachine/wordmachine.c ../../wordmachine/charmachine.c -lm