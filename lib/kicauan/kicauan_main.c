#include <stdio.h>
#include "kicauan.h" 
#include "../adt.h"

int main() {
    ListAcc acc;
    Affection friends;
    ListKicauan myKicauanList;
    CreateListAccount(&acc);
    CreateAffection(&friends);
    CreateListKicauan(&myKicauanList, 10); 

    int choice;
    int idKicauan;

    while (1) {
        printf("Menu:\n");
        printf("1. KICAU (Create Kicauan)\n");
        printf("2. KICAUAN (Display Kicauan)\n");
        printf("3. SUKA_KICAUAN (Like Kicauan)\n");
        printf("4. UBAH_KICAUAN (Edit Kicauan)\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Create Kicauan
                CreateTwit(&myTwit);
                insertLast_ListKicauan(&myKicauanList, myTwit);
                SuccessTwit(myTwit);
                break;
            case 2:  // Display Kicauan
                DisplayListKicauan(myKicauanList);
                break;
            case 3:  // Like Kicauan
                printf("Enter the ID of the Kicauan you want to like: ");
                scanf("%d", &idKicauan);
                LikeKicauan(&myKicauanList, idKicauan);
                break;
            case 4:  // Edit Kicauan
                printf("Enter the ID of the Kicauan you want to edit: ");
                scanf("%d", &idKicauan);
                EditKicauan(&myKicauanList, idKicauan);
                break;
            case 0:  // Exit
                dealocateList(&myKicauanList);  // Clean up memory.
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
