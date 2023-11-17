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
    while ((currentChar != MARK && currentWord.Length<NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        if (i >= NMax) {
            break;
        } else {
            i++;
        }
    }
    // ADV();
    currentWord.Length = i;
    while ((currentChar != MARK)) {
        ADV();
    }
    ADV();
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
    int ASCII = (int) a;
    if ((ASCII > 64) && (ASCII < 91)){ASCII += 32;}
    char CHARA = (char) ASCII;
    return CHARA;
}

boolean wordSimilar (Word W1, Word W2) {
    // untuk masukan case sensitive (huruf besar dan huruf kecil dianggap beda)
    boolean check = true;
    int i;
    if (W1.Length == W2.Length) {
        for (i = 0; i < W1.Length; i++) {
            if (W1.TabWord[i] != W2.TabWord[i]) {
                check = false; break;
            }
        }
    } else {
        check = false;
    }
    return check;
}

boolean wordSimilarCI (Word W1, Word W2) {
    // untuk masukan case insensitive (huruf besar dan huruf kecil dianggap sama)
    boolean check = true;
    int i;
    if (W1.Length == W2.Length) {
        for (i = 0; i < W1.Length; i++) {
            if (ToLowerCase(W1.TabWord[i]) != ToLowerCase(W2.TabWord[i])) {
                check = false; break;
            }
        }
    } else {
        check = false;
    }
    return check;
}

boolean wordSimilarWithoutLength (Word W1, Word W2) {
    boolean check = true;
    int i;
    for (i = 0; i < W2.Length; i++) {
        if (W1.TabWord[i] != W2.TabWord[i]) {
            check = false; break;
        }
    }
    return check;
}

boolean isWordSimilar(Word W, char *W2){
    int i = 0;
    while (W.TabWord[i] != '\0' && W2[i] != '\0') {
        if (W.TabWord[i] != W2[i]) {
            return false;
        }
        i++;
    }
    return (W.TabWord[i] == '\0' && W2[i] == '\0');
}

int Akuisisi_First_Integer (Word W){
    // contoh masukan "VHJVJGJGJasdasea 234" keluaran 234, keluaran default 0
    int Int1 = 0;
    boolean space = false;
    boolean negatif = false;
    for (int i = 0; i < W.Length; i++){
        if ((((int) W.TabWord[i]) < 48 || ((int) W.TabWord[i]) > 57) && space){break;}
        if (W.TabWord[i] == '-'){negatif = true; space = true;}
        else if (((int) W.TabWord[i]) >= 48 && ((int) W.TabWord[i]) <= 57){
            Int1 *= 10; Int1 += W.TabWord[i] - '0'; space = true;
        }
    }
    if (negatif){Int1 *= -1;}
    return Int1;
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

boolean substring_beginning (Word W1, Word W2) {
    int i;
    int len;
    boolean check = true;
    if (W1.Length >= W2.Length) {
        len = W2.Length;
    } else {
        len = W1.Length;
    }
    for (i = 0; i < len; i++) {
        if (W1.TabWord[i] != W2.TabWord[i]) {
            check = false;
            return check;
        }
    }
    return check;
}