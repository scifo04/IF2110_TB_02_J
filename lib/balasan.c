#include "tree/tree.c"
#include "wordmachine/wordmachine.c"
#include "datetime/datetime.c"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IDKicau, IDBalasan;
int id;
DATETIME Date;
Word username;
Word input;

void Balas(Word input) {
    int space_count, result1, result2, stop;
    space_count = result1 = result2 = stop = 0;
    for (int i = 0; input.TabWord[i] != EndWord; i++) {
        if (input.TabWord[i] == BLANK) {
            space_count++;
            if (input.TabWord[i] == BLANK && stop == 0) {
                stop = i;
            }
        }
        else if ((int)input.TabWord[i] >= 48 && (int)input.TabWord[i] <= 57) {
            if (space_count == 1) {
                result1 = result1 * 10 + (input.TabWord[i] - '0');
            }
            else if (space_count == 2) {
                result2 = result2 * 10 + (input.TabWord[i] - '0');
            }
        }
    }
    if (result1 == 1) { // IdKicau EXIST (ADA)
        if (result2 == 2) { // IdBalasan EXIST
            printf("Masukkan balasan:");
            STARTWORD();
            printf("Selamat! balasan telah diterbitkan!\nDetil balasan:");
            printf("| ID = \n"); // ID PENGGUNA
            printf("| \n"); // USERNAME
            printf("| "); // DATETIME
            printf("\n");
            for (int i = 0; i < stop - 1; i++) {
                printf("%c", input.TabWord[i]);
            }
        }
        else { // IdBalas NOT EXIST
            printf("Wah, tidak terdapat balasan yang ingin anda balas!\n");
        }
    }
    else { // IdKicau NOT EXIST
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    }
}

void Balasan(input) {
    printf("| ID = %d\n"), id;
    printtf("| \n");
    printf("| ");
    printf("\n");
}

void hapusBalasan(IDKicau, IDBalasan);