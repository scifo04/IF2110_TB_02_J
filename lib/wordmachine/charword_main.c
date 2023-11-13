#include <stdio.h>
#include "charmachine.h"
#include "charmachine.c"
#include "wordmachine.h"
#include "wordmachine.C"

int main () {

    STARTWORD();
    printf("Current word: ");
    printWord(currentWord);
    if(isWordSimilar(currentWord, "KICAU")){
        printf("BERHASIL KICAU\n");
    } else {
        printf("GAGAL KICAU\n");
    }
    return 0;
}