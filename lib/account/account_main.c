#include <stdio.h>
#include "account.h"
#include "../wordmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"

int main () {
    Word Legi = copyWord_Legi();
    Word Pon = copyWord_Kliwon();
    Word Wage = copyWord_Wage();
    Word Kliwon = copyWord_Kliwon();
    Word Pahing = copyWord_Pahing();
    Word YA = copyWord_YA();
    Word TIDAK = copyWord_TIDAK();
    Account A,B;
    Word W,W2,W3;
    ListAcc L;
    CreateAccount(&A);
    int random;
    scanf("%d",&random);
    // FILE *ptr = fopen("in.txt","r");
    // fscanf(ptr,"%d",&random);
    // printf("%d",random);
    switch(random) {
        case 1:
            readUsername(&A);
            printf("\n");
            break;
        case 2:
            readPassword(&A);
            printf("\n");
            break;
        case 3:
            readBio(&A);
            printf("\n");
            break;
        case 4:
            readPhone_Num(&A);
            printf("\n");
            break;
        case 5:
            readWeton(&A);
            printf("\n");
            break;
        case 6:
            readPhoto(&A);
            printf("\n");
            break;
        case 7:
            change_publicity(&A);
            printf("\n");
            break;
        case 8:
            readUsername(&A);
            readPassword(&A);
            readBio(&A);
            readPhone_Num(&A);
            readWeton(&A);
            readPhoto(&A);
            change_publicity(&A);
            displayAccount(A);
            displayPhoto(A.photo);
            printf("\n");
            break;
        case 9:
            CreateListAccount(&L);
            if (isEmpty_Account(L)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 10:
            CreateListAccount(&L);
            L.NEff = 20;
            if (isFull_Account(L)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 11:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 5; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            if (length_Account(L) == 5) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 12:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            displayAccount(getElmt_Account(L,3));
            printf("\n");
            break;
        case 13:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            L.buffer[6] = B;
            L.NEff += 1;
            int c = getIdx_Account(L,B);
            printf("%d\n",c);
            if (c == 6) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 14:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            setElmt_Account(&L,3,B);
            displayAccount(getElmt_Account(L,3));
            printf("\n");
            displayPhoto(getElmt_Account(L,3).photo);
            printf("\n");
            break;
        case 15:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            displayAccount(getElmt_Account(L,6));
            printf("\n");
            displayPhoto(getElmt_Account(L,6).photo);
            printf("\n");
            break;
        case 16:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            displayList_Account(L);
            printf("\n");
            break;
        case 17:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            Word bruh;
            CopyWord_Any(&bruh,"aspal");
            if (nameAvailable(L,bruh)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 18:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            Word bruh2;
            CopyWord_Any(&bruh2,"aspal");
            if (passAvailable(L,bruh2)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 19:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            Word bruh3;
            CopyWord_Any(&bruh3,"aspal");
            int e =  getIdx_Username(L,bruh3);
            if (e == 6) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 20:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            Word bruh4 = getUsernamebyID(L,6);
            printWord(bruh4);
            printf("\n");
            if (isWordSimilar(bruh4,"aspal")) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 21:
            CreateListAccount(&L);
            CopyWord_Any(&W,"pasta");
            CopyWord_Any(&W2,"4823048932");
            CopyWord_Any(&W3,"Pahing");
            A.username = W;
            A.password = W;
            A.bio = W;
            A.phone_num = W2;
            A.weton = W3;
            for (int i = 0; i < 6; i++) {
                L.buffer[i] = A;
                L.NEff += 1;
            }
            CreateAccount(&B);
            CopyWord_Any(&B.username,"aspal");
            CopyWord_Any(&B.password,"aspal");
            CopyWord_Any(&B.bio,"aspal");
            CopyWord_Any(&B.phone_num,"2423234234");
            CopyWord_Any(&B.weton,"Pahing");
            insertLast_Account(&L,B);
            if (!getPublicitybyUsername(L,B.username)^getPublicitybyUsername(L,getElmt_Account(L,6).username)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
    }
    return 0;
}