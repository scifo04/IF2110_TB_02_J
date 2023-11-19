#include <stdio.h>
#include "affection.h"

void CreateAffection (Affection *A) {
    int i,j;
    for (i = 0; i < ROW_CAP_AFF; i++) {
        for (j = 0; j < COL_CAP_AFF; j++) {
            if (i == j) {
                (*A).status[i][j] = 1;
            } else {
                (*A).status[i][j] = 0;
            }
        }
    }
}

boolean isFriends_Affection (Affection A, int idx1, int idx2) {
    return (((A).status[idx1][idx2] == 1) && ((A).status[idx2][idx1] == 1));
}

void convertAffection (Affection *A, int idx1, int idx2) {
    if (isFriends_Affection((*A),idx1,idx2)) {
        STAT((*A),idx1,idx2) = 0;
        STAT((*A),idx2,idx1) = 0;
    } else {
        STAT((*A),idx1,idx2) = 1;
        STAT((*A),idx2,idx1) = 1;
    }
}

void displayAffection (Affection A) {
    for (int i = 0; i < ROW_CAP_AFF; i++) {
        for (int j = 0; j < COL_CAP_AFF; j++) {
            printf("%d ",(A).status[i][j]);
        }
        printf("\n");
    }
}

int countFriends_Affection (Affection A, int idx) {
    int i,count;
    count = 0;
    for (i = 0; i < 20; i++) {
        if (STAT(A,idx,i) == 1 && i != idx) {
            count += 1;
        }
    }
    return count;
}