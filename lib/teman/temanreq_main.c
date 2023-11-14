#include <stdio.h>
#include "temanreq.h"
#include "temanreq.c" //khusus shulha, nanti di hapus
#include "../account/account.c"
#include "../affection/affection.c"
#include "../datetime/datetime.c"
#include "../kicauan/kicauan.c"
#include "../pcolor/pcolor.c"
#include "../listdin/listdin.c"
#include "../liststatik/liststatik.c"
#include "../matrix/matrix.c"
#include "../queue/queue.c"
#include "../stack/stack.c"
#include "../datetime/time.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

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
    Affection friends;
    dummyAffection(&friends);

    // Initialize QueueFR
    // QueueFR friendRequests;
    // CreateQueueFR(&friendRequests);

    QueueFR qself, qRequested;

    boolean on = true;
    while(on){
        currentWord.TabWord[0] = '\0'; //Mengosongkan currentWord
        currentWord.Length = 0;
        STARTWORD();
        printWord(currentWord);
        if(isWordSimilar(currentWord, "TAMBAH_TEMAN")){
            qself = currentuser.friend_requests;
            qRequested = acc[1].friend_requests;
            addFriend(qSelf, &qRequested, acc, currentuser, friends);
        } else if(isWordSimilar(currentWord, "DAFTAR_PERMINTAAN_PERTEMANAN")){
            qself = currentuser.friend_requests;
            displayFriendRequests(qself, acc);
        } else if(isWordSimilar(currentWord, "SETUJUI_PERTEMANAN")){
            qself = currentuser.friend_requests;
            processRequest(&qself, friends, acc);
        } else if(isWordSimilar(currentWord, "DONE")){
            on=false;
        } else {
            printf("GAGAL KICAU\n");
        }
    }

    return 0;
}
