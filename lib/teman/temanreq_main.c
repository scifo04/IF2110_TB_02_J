#include <stdio.h>
#include "temanreq.h"
#include "temanreq.c" //khusus shulha, nanti di hapus
#include "../account/account.c"
#include "../affection/affection.c"
#include "../datetime/datetime.c"
#include "../pcolor/pcolor.c"
#include "../listdin/listdin.c"
#include "../liststatik/liststatik.c"
#include "../matrix/matrix.c"
#include "../queue/queue.c"
#include "../stack/stack.c"
#include "../datetime/time.c"
#include "../wordmachine/wordmachine.c"
#include "../wordmachine/charmachine.c"

void createDummyListAccountsFR(ListAcc *ACC){
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
    insertLast_Account(ACC, account1);

    // Account 2
    CreateAccount(&account2);
    readUsername(&account2);
    readPassword(&account2);
    readBio(&account2);
    readPhone_Num(&account2);
    readWeton(&account2);
    // Set arbitrary values for photo content
    PICROW(account2.photo, 0, 0) = 'A';
    PICROW(account2.photo, 0, 1) = 'B';
    PICROW(account2.photo, 1, 0) = 'C';
    PICROW(account2.photo, 1, 1) = 'D';
    PICROW(account2.photo, 2, 0) = 'E';
    PICROW(account2.photo, 2, 1) = 'F';
    PICROW(account2.photo, 3, 0) = 'G';
    PICROW(account2.photo, 3, 1) = 'H';
    PICROW(account2.photo, 4, 0) = 'I';
    PICROW(account2.photo, 4, 1) = 'J';
    change_publicity(&account2);
    insertLast_Account(ACC, account2);

    // Account 3
    CreateAccount(&account3);
    readUsername(&account3);
    readPassword(&account3);
    readBio(&account3);
    readPhone_Num(&account3);
    readWeton(&account3);
    // Set arbitrary values for photo content
    PICROW(account3.photo, 0, 0) = 'A';
    PICROW(account3.photo, 0, 1) = 'B';
    PICROW(account3.photo, 1, 0) = 'C';
    PICROW(account3.photo, 1, 1) = 'D';
    PICROW(account3.photo, 2, 0) = 'E';
    PICROW(account3.photo, 2, 1) = 'F';
    PICROW(account3.photo, 3, 0) = 'G';
    PICROW(account3.photo, 3, 1) = 'H';
    PICROW(account3.photo, 4, 0) = 'I';
    PICROW(account3.photo, 4, 1) = 'J';
    change_publicity(&account3);
    insertLast_Account(ACC, account3);

    // Display the list of accounts
    displayList_Account(*ACC);
}


int main() {
    // Inisialisasi Dummy
    ListAcc accounts; createDummyListAccountsFR(&accounts);
    Account currentuser=accounts.buffer[0];
    Affection friends; CreateAffection(&friends);

    // Inisialisasi Queue dan Eltype Queue (FriendRequest)
    QueueFR friendRequests; CreateQueueFR(&friendRequests);
    FriendRequest FR1, FR2;
    CreateFriendRequest(&FR1, 1, 3, friends);
    CreateFriendRequest(&FR2, 2, 3, friends);
    ELFRType val;

    printf("Is the queue empty: %s\n", isEmptyQueueFR(friendRequests) ? "true" : "false");
    printf("Queue length: %d\n", length_QueueFR(friendRequests));
    printf("\n");

    enQueueFR(&friendRequests, FR1);
    enQueueFR(&friendRequests, FR2);
    printf("Friend Requests after Enqueue:\n");
    displayFriendRequests(friendRequests, accounts);
    printf("\n");

    printf("Is the queue empty after enqueuing: %s\n", isEmptyQueueFR(friendRequests) ? "true" : "false");
    printf("Queue length after enqueuing: %d\n", length_QueueFR(friendRequests));
    printf("\n");

    deQueueFR(&friendRequests, &val);
    printf("Friend Requests after Dequeue:\n");
    displayFriendRequests(friendRequests, accounts);
    printf("\n");

    return 0;
}
