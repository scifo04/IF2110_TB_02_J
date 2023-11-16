#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../boolean/boolean.h"
#include "../wordmachine/wordmachine.h"
#include "../pcolor/pcolor.h"

typedef struct {
    char content[5][20];
} Pics;

typedef struct {
    Word username;
    Word password;
    Word bio;
    Word phone_num;
    Word weton;
    Pics photo;
    boolean publicity;
} Account;

typedef struct {
    Account buffer[20];
    int NEff;
} ListAcc;

#define PICROW(x,i,j) (x).content[(i)][(j)]
#define IDX_ACCOUNT_UNDEF -1

Word copyWord_Pahing ();
Word copyWord_Legi ();
Word copyWord_Pon ();
Word copyWord_Wage ();
Word copyWord_Kliwon ();
Word copyWord_YA ();
Word copyWord_TIDAK ();
void CreateAccount (Account *A);
void readUsername (Account *A);
void readPassword (Account *A);
void readBio (Account *A);
void readPhone_Num (Account *A);
void readWeton (Account *A);
void readPhoto (Account *A);
void displayPhoto (Pics P);
void change_publicity (Account *A);
void displayAccount (Account A);
void CreateListAccount (ListAcc *L);
boolean isEmpty_Account (ListAcc L);
boolean isFull_Account (ListAcc L);
int length_Account (ListAcc L);
Account getFirstElmt_Account (ListAcc L);
Account getLastElmt_Account (ListAcc L);
Account getElmt_Account (ListAcc L, int idx);
int getIdxFirst_Account (ListAcc L);
int getIdxLast_Account (ListAcc L);
int getIdx_Account (ListAcc L, Account A);
void setElmt_Account (ListAcc *L, int idx, Account A);
void insertFirst_Account (ListAcc *L, Account A);
void insertLast_Account (ListAcc *L, Account A);
void insertAt_Account (ListAcc *L, int idx, Account A);
void deleteFirst_Account (ListAcc *L, Account *A);
void deleteLast_Account (ListAcc*L, Account  *A);
void deleteAt_Account (ListAcc*L, int idx, Account *A);
void displayList_Account (ListAcc L);
boolean nameAvailable (ListAcc L, Word U);
boolean passAvailable (ListAcc L, Word U);
Word getUsernamebyID (ListAcc L, int id);
int getIdx_Username(ListAcc L, Word U);
boolean getPublicitybyUsername(ListAcc L, Word username);

#endif