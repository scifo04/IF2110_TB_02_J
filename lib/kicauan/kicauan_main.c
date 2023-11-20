// Driver ADT List Dinamis Kicauan dengan Elemen Bertipe Struct Twit

#include <stdio.h>
#include "kicauan.h"
#include "../account/account.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "../affection/affection.h"

void createDummyListAccounts(ListAcc *ACC){
    CreateListAccount(ACC);

    // Create and add three accounts to the list
    Account account1, account2;

    // Account 1
    CreateAccount(&account1);
    readUsername(&account1);
    readPassword(&account1);
    readBio(&account1);
    readPhone_Num(&account1);
    readWeton(&account1);
    // Set arbitrary values for photo content
    PICROW(account1.photo, 0, 0) = 'A';
    PICROW(account1.photo, 0, 1) = 'B';
    PICROW(account1.photo, 1, 0) = 'C';
    PICROW(account1.photo, 1, 1) = 'D';
    PICROW(account1.photo, 2, 0) = 'E';
    PICROW(account1.photo, 2, 1) = 'F';
    PICROW(account1.photo, 3, 0) = 'G';
    PICROW(account1.photo, 3, 1) = 'H';
    PICROW(account1.photo, 4, 0) = 'I';
    PICROW(account1.photo, 4, 1) = 'J';
    change_publicity(&account1);
    insertLast_Account(ACC, account1);

    // Account 2
    CreateAccount(&account2);
    readUsername(&account2);
    readPassword(&account2);
    readBio(&account2);
    readPhone_Num(&account2);
    readWeton(&account2);
    // Set arbitrary values for photo content
    PICROW(account1.photo, 0, 0) = 'A';
    PICROW(account1.photo, 0, 1) = 'B';
    PICROW(account1.photo, 1, 0) = 'C';
    PICROW(account1.photo, 1, 1) = 'D';
    PICROW(account1.photo, 2, 0) = 'E';
    PICROW(account1.photo, 2, 1) = 'F';
    PICROW(account1.photo, 3, 0) = 'G';
    PICROW(account1.photo, 3, 1) = 'H';
    PICROW(account1.photo, 4, 0) = 'I';
    PICROW(account1.photo, 4, 1) = 'J';
    change_publicity(&account2);
    insertLast_Account(ACC, account2);

    // Display the list of accounts
    displayList_Account(*ACC);
}

void createDummyTwit(Twit *twit, int idKicau, Word author) {
    twit->idKicau = idKicau;
    twit->like = 0;
    twit->idUtas = -1;

    twit->author = author;

    DATETIME D; CreateDATETIME(&D); twit->datetime = D; 

    twit->isiTwit.TabWord[0] = 'D'; twit->isiTwit.TabWord[1] = 'u'; twit->isiTwit.TabWord[2] = 'm';  twit->isiTwit.TabWord[3] = 'm'; twit->isiTwit.TabWord[4] = 'y'; 
    twit->isiTwit.Length = 5;

    twit->tagar.TabWord[0] = 'D';
    twit->tagar.Length = 1;
}

int main(){
    // Inisialisasi Dummy
    ListAcc accounts; createDummyListAccounts(&accounts);
    Account currentuser = accounts.buffer[0];
    Affection friends; CreateAffection(&friends);
    int lenKicauan; Twit K1, K2, K3; IdxType index1, index2;

    // Tes ADT List Dinamis Kicauan
    ListKicauan Kicauan;
    CreateListKicauan(&Kicauan, 2);
    /*----------------------------------------------------------------------------------------------------*/
     // Test Test Validasi
    lenKicauan = listLength_ListKicauan(Kicauan);
    printf("List Length: %d\n", lenKicauan);

    // Test index valid
    index1 = 1;
    index2 = 15;
    printf("Index %d is valid: %s\n", index1, isIdxValid_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is valid: %s\n", index2, isIdxValid_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test index efektif
    printf("Index %d is effective: %s\n", index1, isIdxEff_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is effective: %s\n", index2, isIdxEff_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test if the list is empty
    printf("Is the list empty: %s\n", isEmpty_ListKicauan(Kicauan) ? "true" : "false");

    // Test if the list is full
    printf("Is the list full: %s\n", isFull_ListKicauan(Kicauan) ? "true" : "false");

    createDummyTwit(&K1, lenKicauan+1, currentuser.username);
    insertLast_ListKicauan(&Kicauan, K1);

    // Menampilkan list kicauan
    printf("List Kicauan:\n");
    DisplayListKicauan(Kicauan, currentuser, friends, accounts);

    /*----------------------------------------------------------------------------------------------------*/

    // Test Test Validasi
    lenKicauan = listLength_ListKicauan(Kicauan);
    printf("List Length: %d\n", lenKicauan);

    // Test index valid
    index1 = 1;
    index2 = 15;
    printf("Index %d is valid: %s\n", index1, isIdxValid_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is valid: %s\n", index2, isIdxValid_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test index efektif
    printf("Index %d is effective: %s\n", index1, isIdxEff_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is effective: %s\n", index2, isIdxEff_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test if the list is empty
    printf("Is the list empty: %s\n", isEmpty_ListKicauan(Kicauan) ? "true" : "false");

    // Test if the list is full
    printf("Is the list full: %s\n", isFull_ListKicauan(Kicauan) ? "true" : "false");

    createDummyTwit(&K2, listLength_ListKicauan(Kicauan)+1, currentuser.username);
    insertLast_ListKicauan(&Kicauan, K2);

    // Menyalin list kicauan
    ListKicauan copiedKicauan;
    copyList_ListKicauan(Kicauan, &copiedKicauan);
    printf("\nCopied List Kicauan:\n");
    DisplayListKicauan(copiedKicauan,currentuser, friends, accounts);

    /*----------------------------------------------------------------------------------------------------*/

     // Test Test Validasi
    lenKicauan = listLength_ListKicauan(Kicauan);
    printf("List Length: %d\n", lenKicauan);

    // Test index valid
    index1 = 1;
    index2 = 15;
    printf("Index %d is valid: %s\n", index1, isIdxValid_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is valid: %s\n", index2, isIdxValid_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test index efektif
    printf("Index %d is effective: %s\n", index1, isIdxEff_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is effective: %s\n", index2, isIdxEff_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test if the list is empty
    printf("Is the list empty: %s\n", isEmpty_ListKicauan(Kicauan) ? "true" : "false");

    // Test if the list is full
    printf("Is the list full: %s\n", isFull_ListKicauan(Kicauan) ? "true" : "false");

    createDummyTwit(&K3, listLength_ListKicauan(Kicauan)+1, currentuser.username);
    insertLast_ListKicauan(&Kicauan, K3);

     // Mengubah ukuran list kicauan
    expandListKicauan(&Kicauan, 2);
    printf("\nExpanded List Kicauan:\n");
    DisplayListKicauan(Kicauan, currentuser, friends, accounts);

    /*----------------------------------------------------------------------------------------------------*/
     // Test Test Validasi
    lenKicauan = listLength_ListKicauan(Kicauan);
    printf("List Length: %d\n", lenKicauan);

    // Test index valid
    index1 = 1;
    index2 = 15;
    printf("Index %d is valid: %s\n", index1, isIdxValid_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is valid: %s\n", index2, isIdxValid_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test index efektif
    printf("Index %d is effective: %s\n", index1, isIdxEff_ListKicauan(Kicauan, index1) ? "true" : "false");
    printf("Index %d is effective: %s\n", index2, isIdxEff_ListKicauan(Kicauan, index2) ? "true" : "false");

    // Test if the list is empty
    printf("Is the list empty: %s\n", isEmpty_ListKicauan(Kicauan) ? "true" : "false");

    // Test if the list is full
    printf("Is the list full: %s\n", isFull_ListKicauan(Kicauan) ? "true" : "false");

    // Dealokasi list kicauan
    dealocateListKicauan(&Kicauan);
    printf("\nSetelah Dealokasi List Kicauan:\n");
    DisplayListKicauan(Kicauan, currentuser, friends, accounts);

    // Test if the list is empty
    printf("Is the list empty: %s\n", isEmpty_ListKicauan(Kicauan) ? "true" : "false");

    return 0;
}