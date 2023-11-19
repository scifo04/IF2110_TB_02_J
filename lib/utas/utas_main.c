#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

extern int idUtas;

int main(int argc, char *argv[]){
    AddressUtas U; CreateUtas(&U);
    DATETIME D; CreateDATETIME(&D);
    Word Author; Author.TabWord[0] = 'J'; Author.TabWord[1] = 'o'; Author.TabWord[2] = 'e'; Author.Length = 3;
    Word isiUtas; isiUtas.TabWord[0] = 'L'; isiUtas.TabWord[1] = 'O'; isiUtas.TabWord[2] = 'L'; isiUtas.Length = 3;
    switch (argv[1][0] - '0') {
    case 1: // tes kosong
        printf("%d", isEmpty_Utas(U));
        cetakUtas(U, Author);
        break;
    case 2: // insertAtUtas
        CreateDATETIME(&D);
        insertAtUtas(&U, D, isiUtas, 1);
        isiUtas.TabWord[1] = 'o';
        insertAtUtas(&U, D, isiUtas, 1);
        isiUtas.TabWord[2] = 'l';
        insertAtUtas(&U, D, isiUtas, 3);
        cetakUtas(U, Author);
        break;
    case 3: // insertLastUtas
        CreateDATETIME(&D);
        insertLastUtas(&U, D, isiUtas);
        isiUtas.TabWord[1] = 'o';
        insertLastUtas(&U, D, isiUtas);
        cetakUtas(U, Author);
        break;
    case 4: // deleteAtUtas
        CreateDATETIME(&D);
        insertAtUtas(&U, D, isiUtas, 1);
        isiUtas.TabWord[1] = 'o';
        insertAtUtas(&U, D, isiUtas, 1);
        isiUtas.TabWord[2] = 'l';
        insertAtUtas(&U, D, isiUtas, 3);
        deleteAtUtas(&U, 3);
        cetakUtas(U, Author);
        deleteAtUtas(&U, 1);
        cetakUtas(U, Author);
        deleteAtUtas(&U, 1);
        cetakUtas(U, Author);
        break;
    case 5: // tes panjang
        printf("%d", lengthUtas(U));
        insertAtUtas(&U, D, isiUtas, 1);
        printf("%d", lengthUtas(U));
        insertAtUtas(&U, D, isiUtas, 1);
        printf("%d", lengthUtas(U));
        insertAtUtas(&U, D, isiUtas, 3);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 3);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 1);
        printf("%d", lengthUtas(U));
        deleteAtUtas(&U, 1);
        printf("%d", lengthUtas(U));
        break;
    default:
        break;
    }
    return 0;
} //gcc -o utas_main utas_main.c utas.c ../datetime/datetime.c ../datetime/time.c ../wordmachine/wordmachine.c ../wordmachine/charmachine.c -lm