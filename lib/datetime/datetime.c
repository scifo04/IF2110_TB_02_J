#include <stdio.h>
#include "datetime.h"

void CreateDATETIME(DATETIME *D) {
    int total;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Month(*D) = tm.tm_mon + 1;
    Year(*D) = tm.tm_year + 1900;
    total = tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_sec;
    Time(*D) = DetikToTIME(total);
}

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

// boolean DLT(DATETIME D1, DATETIME D2) {
//     return ((Year(D1) < Year(D2)) || (Month(D1) < Month(D2)) || (Day(D1) < Day(D2)) || (Hour(Time(D1)) < Hour(Time(D2))) || (Minute(Time(D1)) < Minute(Time(D2))) || (Second(Time(D1)) < Second(Time(D2))));
// }
// boolean DGT(DATETIME D1, DATETIME D2) {
//     return ((Year(D1) > Year(D2)) || (Month(D1) > Month(D2)) || (Day(D1) > Day(D2)) || (Hour(Time(D1)) > Hour(Time(D2))) || (Minute(Time(D1)) > Minute(Time(D2))) || (Second(Time(D1)) > Second(Time(D2))));
// }

// long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh) {
//     long int total1, total2;
//     if (GetMaxDay(2, Year(DAw) == 29)) {
//         total1 = TIMEToDetik(Time(DAw)) + (Day(DAw) * 86400) + (Month(DAw) * GetMaxDay(Month(DAw), Year(DAw)) * 86400) + (366 * 86400);
//     }
//     else {
//         total1 = TIMEToDetik(Time(DAw)) + (Day(DAw) * 86400) + (Month(DAw) * GetMaxDay(Month(DAw), Year(DAw)) * 86400) + (365 * 86400);
//     }

//     if (GetMaxDay(2, Year(DAkh) == 29)) {
//         total2 = TIMEToDetik(Time(DAkh)) + (Day(DAkh) * 86400) + (Month(DAkh) * GetMaxDay(Month(DAkh), Year(DAkh)) * 86400) + (366 * 86400);
//     }
//     else {
//         total2 = TIMEToDetik(Time(DAkh)) + (Day(DAkh) * 86400) + (Month(DAkh) * GetMaxDay(Month(DAkh), Year(DAkh)) * 86400) + (365 * 86400);
//     }
//     return total2-total1;
// }