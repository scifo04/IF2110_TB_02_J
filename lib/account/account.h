#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../boolean/boolean.h"
#include "../wordmachine/wordmachine.h"

typedef struct {
    Word username;
    Word password;
} Account;

typedef struct {
    Account buffer[20];
    int NEff;
} ListAcc;

void readAccount (Account *A);
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

#endif