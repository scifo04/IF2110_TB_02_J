#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
    while (currentChar == BLANK) {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD() {
    START();
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
        currentWord.Length = 0;
    } else {
        EndWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD() {
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
    }
    IgnoreBlanks();
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord() {
    int i;
    i = 0;
    while ((currentChar != MARK)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        if (i >= NMax) {
            break;
        } else {
            i++;
        }
    }
    ADV();
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void printWord(Word W) {
    int i;
    for (i = 0; i < W.Length; i++) {
        printf("%c",W.TabWord[i]);
    }
}

char ToLowerCase (char a){
    if (a == 'A'){return 'a';} if (a == 'B'){return 'b';} if (a == 'C'){return 'c';}
    if (a == 'D'){return 'd';} if (a == 'E'){return 'e';} if (a == 'F'){return 'f';}
    if (a == 'G'){return 'g';} if (a == 'H'){return 'h';} if (a == 'I'){return 'i';}
    if (a == 'J'){return 'j';} if (a == 'K'){return 'k';} if (a == 'L'){return 'l';}
    if (a == 'M'){return 'm';} if (a == 'N'){return 'n';} if (a == 'O'){return 'o';}
    if (a == 'P'){return 'p';} if (a == 'Q'){return 'q';} if (a == 'R'){return 'r';}
    if (a == 'S'){return 's';} if (a == 'T'){return 't';} if (a == 'U'){return 'u';}
    if (a == 'V'){return 'v';} if (a == 'W'){return 'w';} if (a == 'X'){return 'x';}
    if (a == 'Y'){return 'y';} if (a == 'Z'){return 'z';} return a;
}

boolean wordSimilar (Word W1, Word W2) {
    boolean check = true;
    int i;
    if (W1.Length == W2.Length) {
        for (i = 0; i < W1.Length; i++) {
            if (W1.TabWord[i] != W2.TabWord[i]) {
                check = false;
            }
        }
    } else {
        check = false;
    }
    return check;
}

boolean wordSimilarCI (Word W1, Word W2) {
    Word WI, WO;
    PasteWord(W1, &WI); PasteWord(W2, &WO);
    int i;
    for (i = 0; i < WI.Length; i++){
        WI.TabWord[i] = ToLowerCase(WI.TabWord[i]);
    }
    for (i = 0; i < WO.Length; i++){
        WO.TabWord[i] = ToLowerCase(WO.TabWord[i]);
    }
    return (wordSimilar (WI, WO));
}

void PasteWord(Word WIn, Word *WOut) {
    int i;
    for (i = 0; i < WIn.Length; i++) {
        (*WOut).TabWord[i] = WIn.TabWord[i];
    }
    (*WOut).Length = WIn.Length;
}

boolean intCheck (Word W) {
    boolean check = true;
    for (int i = 0; i < W.Length; i++) {
        if (!(W.TabWord[i] >= 48 && W.TabWord[i] <= 57)) {
            check = false;
            return check;
        }
    }
    return check;
}