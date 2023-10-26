#include <stdio.h>
#include "datetime.h"

int GetMaxDay(int M, int Y) {
    int max;
    if (M == 2) {
        if (Y % 400 == 0) {
            return 29;
        }
        else if (Y % 400 != 0 && Y % 100 == 0) {
            return 28;
        }
        else if (Y % 400 != 0 && Y % 100 != 0 && Y % 4 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) {
        return 31;
    }
    else {
        return 30;
    }
}
boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s) {
    return ((D >= 1 && D <= GetMaxDay(M, Y)) && (M >= 1 && M <= 12) && (Y >= 0 && Y <= 9999) && IsTIMEValid(h, m, s));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss) {
    int total;
    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    total = hh * 3600 + mm * 60 + ss;
    Time(*D) = DetikToTIME(total);
}

void BacaDATETIME(DATETIME *D) {
    int DD, MM, YY, h, m, s;
    scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);
    while (!IsDATETIMEValid(DD, MM, YY, h, m, s)) {
        printf("DATETIME tidak valid");
        scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);
    }
    CreateDATETIME(D, DD, MM, YY, h, m, s);
}

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

boolean DEQ(DATETIME D1, DATETIME D2) {
    return ((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && (Hour(Time(D1)) == Hour(Time(D2))) && (Minute(Time(D1)) == Minute(Time(D2))) && (Second(Time(D1)) == Second(Time(D2))));
}

boolean DNEQ(DATETIME D1, DATETIME D2) {
    return ((Day(D1) != Day(D2)) || (Month(D1) != Month(D2)) || (Year(D1) != Year(D2)) || (Hour(Time(D1)) != Hour(Time(D2))) || (Minute(Time(D1)) != Minute(Time(D2))) || (Second(Time(D1)) != Second(Time(D2))));
}
boolean DLT(DATETIME D1, DATETIME D2) {
    return ((Year(D1) < Year(D2)) || (Month(D1) < Month(D2)) || (Day(D1) < Day(D2)) || (Hour(Time(D1)) < Hour(Time(D2))) || (Minute(Time(D1)) < Minute(Time(D2))) || (Second(Time(D1)) < Second(Time(D2))));
}
boolean DGT(DATETIME D1, DATETIME D2) {
    return ((Year(D1) > Year(D2)) || (Month(D1) > Month(D2)) || (Day(D1) > Day(D2)) || (Hour(Time(D1)) > Hour(Time(D2))) || (Minute(Time(D1)) > Minute(Time(D2))) || (Second(Time(D1)) > Second(Time(D2))));
}
DATETIME DATETIMENextNDetik(DATETIME D, int N) {
    CreateDATETIME(&D, Day(D), Month(D), Year(D), Hour(NextNDetik(Time(D), N)), Minute(NextNDetik(Time(D), N)), Second(NextNDetik(Time(D), N)));
    return D;
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N) {
    CreateDATETIME(&D, Day(D), Month(D), Year(D), Hour(PrevNDetik(Time(D), N)), Minute(PrevNDetik(Time(D), N)), Second(PrevNDetik(Time(D), N)));
    return D;
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
    long int total1, total2;
    if (GetMaxDay(2, Year(DAw) == 29)) {
        total1 = TIMEToDetik(Time(DAw)) + (Day(DAw) * 86400) + (Month(DAw) * GetMaxDay(Month(DAw), Year(DAw)) * 86400) + (366 * 86400);
    }
    else {
        total1 = TIMEToDetik(Time(DAw)) + (Day(DAw) * 86400) + (Month(DAw) * GetMaxDay(Month(DAw), Year(DAw)) * 86400) + (365 * 86400);
    }

    if (GetMaxDay(2, Year(DAkh) == 29)) {
        total2 = TIMEToDetik(Time(DAkh)) + (Day(DAkh) * 86400) + (Month(DAkh) * GetMaxDay(Month(DAkh), Year(DAkh)) * 86400) + (366 * 86400);
    }
    else {
        total2 = TIMEToDetik(Time(DAkh)) + (Day(DAkh) * 86400) + (Month(DAkh) * GetMaxDay(Month(DAkh), Year(DAkh)) * 86400) + (365 * 86400);
    }
    return total2-total1;
}