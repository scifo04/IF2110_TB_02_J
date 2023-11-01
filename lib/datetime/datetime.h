#ifndef DATETIME_H
#define DATETIME_H

#include "../boolean/boolean.h"
#include "../time/time.c"
#include <time.h>

typedef struct {
    int DD;   /* integer [1..31] */
    int MM;   /* integer [1..12] */
    int YYYY; /* integer [1900..2030] */
    TIME T;
} DATETIME;

#define Day(D) (D).DD
#define Month(D) (D).MM
#define Year(D) (D).YYYY
#define Time(D) (D).T

void CreateDATETIME(DATETIME *D);
void TulisDATETIME(DATETIME D);

// boolean DLT(DATETIME D1, DATETIME D2);
// boolean DGT(DATETIME D1, DATETIME D2);

// long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh);

#endif