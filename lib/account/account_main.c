#include <stdio.h>
#include "account.h"
#include "../wordmachine/charmachine.h"
#include "../wordmachine/wordmachine.h"

int main () {
    Word Legi = CopyWord_Any("Legi");
    Word Pon = CopyWord_Any("Pon");
    Word Wage = CopyWord_Any("Wage");
    Word Kliwon = CopyWord_Any("Kliwon");
    Word Pahing = CopyWord_Any("Pahing");
    Word YA = CopyWord_Any("YA");
    Word TIDAK = CopyWord_Any("TIDAK");
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
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
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
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            setElmt_Account(&L,3,B);
            displayAccount(getElmt_Account(L,3));
            printf("\n");
            displayPhoto(getElmt_Account(L,3).photo);
            printf("\n");
            break;
        case 15:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            displayAccount(getElmt_Account(L,6));
            printf("\n");
            displayPhoto(getElmt_Account(L,6).photo);
            printf("\n");
            break;
        case 16:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            displayList_Account(L);
            printf("\n");
            break;
        case 17:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            Word bruh;
            bruh = CopyWord_Any("aspal");
            if (nameAvailable(L,bruh)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 18:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            Word bruh2;
            bruh2 = CopyWord_Any("aspal");
            if (passAvailable(L,bruh2)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 19:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            Word bruh3;
            bruh3 = CopyWord_Any("aspal");
            int e =  getIdx_Username(L,bruh3);
            if (e == 6) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 20:
            CreateListAccount(&L);
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
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
            W = CopyWord_Any("pasta");
            W2 = CopyWord_Any("4823048932");
            W3 = CopyWord_Any("Pahing");
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
            B.username = CopyWord_Any("aspal");
            B.password = CopyWord_Any("aspal");
            B.bio = CopyWord_Any("aspal");
            B.phone_num = CopyWord_Any("2423234234");
            B.weton = CopyWord_Any("Pahing");
            insertLast_Account(&L,B);
            if (!getPublicitybyUsername(L,B.username)^getPublicitybyUsername(L,getElmt_Account(L,6).username)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
    }
    return 0;
}