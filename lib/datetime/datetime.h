#ifndef DATETIME_H
#define DATETIME_H

#include "../boolean/boolean.h"
#include "../time/time.h"

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

int GetMaxDay(int M, int Y);
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s);

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss);
void BacaDATETIME(DATETIME *D);
void TulisDATETIME(DATETIME D);

boolean DEQ(DATETIME D1, DATETIME D2);
boolean DNEQ(DATETIME D1, DATETIME D2);
boolean DLT(DATETIME D1, DATETIME D2);
boolean DGT(DATETIME D1, DATETIME D2);
DATETIME DATETIMENextNDetik(DATETIME D, int N);
DATETIME DATETIMEPrevNDetik(DATETIME D, int N);

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh);

#endif