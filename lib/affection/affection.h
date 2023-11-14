#ifndef AFFECTION_H
#define AFFECTION_H

#include "../boolean/boolean.h"

#define ROW_CAP_AFF 20
#define COL_CAP_AFF 20

typedef struct {
    int status[ROW_CAP_AFF][COL_CAP_AFF];
} Affection;

#define STAT(x,i,j) (x).status[(i)][(j)]

void CreateAffection (Affection *A);
boolean isFriends_Affection (Affection A, int idx1, int idx2);
void convertAffection (Affection *A, int idx1, int idx2);
void displayAffection (Affection A);
int countFriends_Affection (Affection A, int idx);

#endif