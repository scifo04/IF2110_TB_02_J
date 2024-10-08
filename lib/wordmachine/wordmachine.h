/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean/boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordFILE(FILE *file);

void printWord(Word W);
void fprintWord(Word W, FILE *file);

char ToLowerCase (char a);
// untuk wordSimilarCI

boolean wordSimilar (Word W1, Word W2);
boolean wordSimilarCI (Word W1, Word W2);
boolean wordSimilarWithoutLength (Word W1, Word W2);
// wordSimilar untuk yang case sensitive
// wordSimilarCI untuk yang case insensitive, untuk validasi weton dan tagar (bonus)
// wordSimiliarWithoutLength ga mengecek panjang word, cek apakah W2 == w1
boolean isWordSimilar(Word W, char *W2);
/*mengembalikan true jika kata W sama dengan string W2*/

int Akuisisi_First_Integer (Word W);
int Akuisisi_Second_Integer (Word W);
/* untuk command-command yang ada tambahan int di belakangnya */

Word CopyWord_Any (char *c);
int strilen (char *c);
void PasteWord(Word WIn, Word *WOut);
boolean intCheck (Word W);
int charToInt (char c);
boolean substring_beginning (Word W1, Word W2);

Word concatWordStart(char* A, Word B);
Word concatWordEnd(Word A, char *B);
/* Untuk save/load */

#endif