#include <stdio.h>
#include "../kicauan/kicauan.h"
#include "../account/account.h"
#include "../datetime/datetime.h"
// #include "../kicauan/kicauan.c"
#include "../pcolor/pcolor.h"
#include "../listdin/listdin.h"
#include "../liststatik/liststatik.h"
#include "../matrix/matrix.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../datetime/time.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"
#include "draft.h"

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

    // Insert the accounts into the list
    insertLast_Account(ACC, account1);

    // Display the list of accounts
    displayList_Account(*ACC);

}


int main() {
    ListAcc acc;
    dummyListAccounts(&acc);
    Account currentuser=acc.buffer[0];
    printf("Aman");
    ListKicauan kicauanList;
    CreateListKicauan(&kicauanList, 10); // Assume capacity is 10, adjust as needed

    // Assume accounts and friends are already initialized
    // Assume currentuser is already initialized
    boolean on = true;
    while(on){
        Draft *S;
        CreateEmpty_Draft(S, currentuser);
        if (IsEmpty_Draft(*S)){
            printf("Draft kosong");
        }

        if (IsFull_Draft(*S)){
            printf("Draft penuh");
        }

        displayDraft(S, kicauanList, currentuser);
        createDraft(S, kicauanList, currentuser);
        displayDraft(S, kicauanList, currentuser);

        if (IsEmpty_Draft(*S)){
            printf("Draft kosong");
        }

        if (IsFull_Draft(*S)){
            printf("Draft penuh");
            on = false;
        }
    }

    return 0;
}
