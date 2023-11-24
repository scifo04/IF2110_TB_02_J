#include <stdio.h>
#include <sys/stat.h>
#include "charmachine.h"
#include "wordmachine.h"

int main () {
    int a;
    scanf("%d",&a);
    switch(a) {
        case 1:
            printf("Masukkan 'Peta': ");
            STARTWORD();
            currentWord.TabWord[currentWord.Length] = '\0';
            if (isWordSimilar(currentWord,"Peta")) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 2:
            printf("Masukkan 'Peta': ");
            FILE *reader = fopen("in.txt","r");
            CopyWordFILE(reader);
            Word a = currentWord;
            STARTWORD();
            if (wordSimilar(a,currentWord)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 3:
            printf("Masukkan 'Peta': ");
            STARTWORD();
            printWord(currentWord);
            break;
        case 4:
            char c;
            printf("Input something in UPPER CASE: ");
            scanf("%c",&a);
            if (c == ToLowerCase(c)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 5:
            printf("Two words has to be similar!\n");
            STARTWORD();
            Word W1 = currentWord;
            STARTWORD();
            Word W2 = currentWord;
            if (wordSimilar(W1,W2)) {
                printf("TRUE 1\n");
            } else {
                printf("FALSE\n");
            }
            if (wordSimilarCI(W1,W2)) {
                printf("TRUE 1\n");
            } else {
                printf("FALSE\n");
            }
            if (wordSimilarWithoutLength(W1,W2)) {
                printf("TRUE 1\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 6:
            char *integerrrr;
            Word INTE;
            INTE.TabWord[0] = '1';
            INTE.TabWord[1] = '2';
            INTE.TabWord[2] = '3';
            INTE.TabWord[3] = '4';
            INTE.TabWord[4] = '5';
            INTE.Length = 5;
            if (Akuisisi_First_Integer(INTE) == 12345) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
    }
}