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
        currentWord="";
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