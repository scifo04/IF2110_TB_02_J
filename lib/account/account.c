#include <stdio.h>
#include "account.h"

void readUsername(Account *A) {
    printf("Masukkan nama: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    (*A).username = currentWord;
}

void readPassword(Account *A) {
    printf("Masukkan kata sandi: ");
    printf("\n");
    STARTWORD();
    printf("\n");
    (*A).password = currentWord;
}

void displayAccount(Account A) {
    printf("[");
    printWord(A.username);
    printf(",");
    printWord(A.password);
    printf("]");
}

void CreateListAccount (ListAcc *L) {
    (*L).NEff = 0;
}

boolean isEmpty_Account (ListAcc L) {
    return L.NEff == 0;
}

boolean isFull_Account (ListAcc L) {
    return L.NEff == 20;
}

int length_Account (ListAcc L) {
    return L.NEff;
}

Account getFirstElmt_Account (ListAcc L) {
    return L.buffer[0];
}

Account getLastElmt_Account (ListAcc L) {
    return L.buffer[L.NEff-1];
}

Account getElmt_Account (ListAcc L, int idx) {
    return L.buffer[idx];
}

int getIdxFirst_Account (ListAcc L) {
    return 0;
}

int getIdxLast_Account (ListAcc L) {
    return 19;
}

int getIdx_Account (ListAcc L, Account A) {
    int i;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(L.buffer[i].username,A.username) && wordSimilar(L.buffer[i].password,A.password)) {
            return i;
        }
    }
}

void setElmt_Account (ListAcc *L, int idx, Account A) {
    (((*L).buffer)[idx]).username = A.username;
    (((*L).buffer)[idx]).password = A.password;
}

void insertFirst_Account (ListAcc *L, Account A) {
    int i;
    if (!isFull_Account(*L)) {
        for (i = 0; i < length_Account(*L); i++) {
            setElmt_Account(&*L,i+1,getElmt_Account(*L,i));
        }
        setElmt_Account(&*L,getIdxFirst_Account(*L),A);
        (*L).NEff += 1;
    }
}

void insertLast_Account (ListAcc *L, Account A) {
    if (!isFull_Account(*L)) {
        setElmt_Account(&(*L),length_Account(*L),A);
        (*L).NEff += 1;
    }
}

void insertAt_Account (ListAcc *L, int idx, Account A) {
    int i;
    if (!isFull_Account(*L)) {
        for (i = idx; i < length_Account(*L); i++) {
            setElmt_Account(&*L,i+1,getElmt_Account(*L,i));
        }
        setElmt_Account(&*L,idx,A);
        (*L).NEff += 1;
    }
}

void deleteFirst_Account (ListAcc *L, Account *A) {
    int i;
    if (!isEmpty_Account(*L)) {
        PasteWord(getFirstElmt_Account(*L).username,(&*A)->username);
        PasteWord(getFirstElmt_Account(*L).password,(&*A)->password);
        for (i = 0; i < length_Account(*L); i++) {
            setElmt_Account(&*L,i,getElmt_Account(*L,i+1));
        }
        (*L).NEff -= 1;
    }
}

void deleteLast_Account (ListAcc *L, Account *A) {
    if (!isEmpty_Account(*L)) {
        PasteWord(getLastElmt_Account(*L).username,(&*A)->username);
        PasteWord(getLastElmt_Account(*L).password,(&*A)->password);
        (*L).NEff -= 1;
    }
}

void deleteAt_Account (ListAcc *L, int idx, Account *A) {
    int i;
    if (!isEmpty_Account(*L)) {
        PasteWord(getElmt_Account(*L,idx).username,(&*A)->username);
        PasteWord(getElmt_Account(*L,idx).password,(&*A)->password);
        for (i = idx; i < length_Account(*L); i++) {
            setElmt_Account(&*L,i,getElmt_Account(*L,i+1));
        }
        (*L).NEff -= 1;
    }
}

void displayList_Account (ListAcc L) {
    int i;
    printf("[");
    if (!isEmpty_Account(L)) {
        for (i = 0; i < length_Account(L)-1; i++) {
            displayAccount(L.buffer[i]);
            printf(",");
        }
        displayAccount(L.buffer[length_Account(L)-1]);
    }
    printf("]");
}

boolean nameAvailable (ListAcc L, Word U) {
    int i;
    boolean check = false;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(U,L.buffer[i].username)) {
            check = true;
            return check;
        }
    }
    return check;
}

boolean passAvailable (ListAcc L, Word U) {
    int i;
    boolean check = false;
    for (i = 0; i < length_Account(L); i++) {
        if (wordSimilar(U,L.buffer[i].password)) {
            check = true;
            return check;
        }
    }
    return check;
}