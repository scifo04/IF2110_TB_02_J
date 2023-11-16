#include <stdio.h>
#include "kicauan.h"
#include "../account/account.h"
#include "../affection/affection.h"
#include "../datetime/datetime.h"
// #include "../kicauan/kicauan.h"
#include "../pcolor/pcolor.h"
#include "../listdin/listdin.h"
#include "../liststatik/liststatik.h"
#include "../matrix/matrix.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../datetime/time.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

void dummyListAccounts(ListAcc *ACC){
    CreateListAccount(ACC);

    // Create and add three accounts to the list
    Account account1, account2, account3;

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

    // Account 2
    CreateAccount(&account2);
    readUsername(&account2);
    readPassword(&account2);
    readBio(&account2);
    readPhone_Num(&account2);
    readWeton(&account2);
    // Set arbitrary values for photo content
    PICROW(account2.photo, 0, 0) = 'K';
    PICROW(account2.photo, 0, 1) = 'L';
    PICROW(account2.photo, 1, 0) = 'M';
    PICROW(account2.photo, 1, 1) = 'N';
    PICROW(account2.photo, 2, 0) = 'O';
    PICROW(account2.photo, 2, 1) = 'P';
    PICROW(account2.photo, 3, 0) = 'Q';
    PICROW(account2.photo, 3, 1) = 'R';
    PICROW(account2.photo, 4, 0) = 'S';
    PICROW(account2.photo, 4, 1) = 'T';
    change_publicity(&account2);

    // Insert the accounts into the list
    insertLast_Account(ACC, account1);
    insertLast_Account(ACC, account2);

    // Display the list of accounts
    displayList_Account(*ACC);

}

void dummyAffection(Affection *friends){
    CreateAffection(friends);

    // Assuming account indices are 0-based
    int account1Index = 0;
    int account2Index = 1;

    // Set arbitrary values for the Affection matrix
    // For example, let's make account 1 friends with account 2
    convertAffection(friends, account1Index, account2Index);

    // Display the Affection matrix
    displayAffection(*friends);
    printf("\n");
}

int main() {
    ListAcc acc;
    dummyListAccounts(&acc);
    Account currentuser=acc.buffer[0];
    ListKicauan kicauanList;
    Affection friends;
    dummyAffection(&friends);
    CreateListKicauan(&kicauanList, 10); // Assume capacity is 10, adjust as needed

    // Assume accounts and friends are already initialized
    // Assume currentuser is already initialized
    boolean on = true;
    while(on){
        currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
        currentWord.Length = 0;
        STARTWORD();
        printWord(currentWord);
        if(isWordSimilar(currentWord, "KICAU")){
            Twit newTwit;
            CreateTwit(&newTwit, kicauanList, currentuser);
            insertLast_ListKicauan(&kicauanList, newTwit);
            SuccessTwit(newTwit);
        } else if(isWordSimilar(currentWord, "KICAUAN")){
            DisplayListKicauan(kicauanList, currentuser, friends, acc);
        } else if(isWordSimilar(currentWord, "LIKE_KICAUAN")){
            LikeKicauan(&kicauanList, 1, currentuser, friends, acc);
            printf("\n");
            LikeKicauan(&kicauanList, 1000, currentuser, friends, acc);
        } else if(isWordSimilar(currentWord, "UBAH_KICAUAN")){
            EditKicauan(&kicauanList, 1, currentuser, acc);
            printf("\n");
            EditKicauan(&kicauanList, 1000, currentuser, acc);
        } else if(isWordSimilar(currentWord, "DONE")){
            on=false;
        } else {
            printf("GAGAL KICAU\n");
        }
    }

    // Clean up memory
    dealocateListKicauan(&kicauanList);

    return 0;
}
