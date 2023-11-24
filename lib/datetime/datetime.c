#include <stdio.h>
#include "datetime.h"

void CreateDATETIME(DATETIME *D) {
    int total;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    Day(*D) = tm.tm_mday;
    Month(*D) = tm.tm_mon + 1;
    Year(*D) = tm.tm_year + 1900;
    total = tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_sec;
    Time(*D) = DetikToTIME(total);
}

void TulisDATETIME(DATETIME D) {
    printf("%d/%d/%d ", Day(D), Month(D), Year(D));
    TulisTIME(Time(D));
}

void TulisDATETIMEFILE(DATETIME D, FILE *file){
    fprintf(file, "%d/%d/%d %02d:%02d:%02d\n", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

DATETIME BacaDateTimeWord(Word W){
    DATETIME D; Day(D) = 0; Month(D) = 0; Year(D) = 0; Hour(Time(D)) = 0; Minute(Time(D)) = 0; Second(Time(D)) = 0;
    int Q = 0;
    for (int i = 0; i < W.Length; i++){
        if (((int)W.TabWord[i] >= 48) && ((int)W.TabWord[i] <= 57)){
            switch (Q) {
                case 0:
                    Day(D) *= 10;
                    Day(D) += W.TabWord[i] - '0';
                    if (W.TabWord[i+1] == '/'){Q++;}
                    break;
                case 1:
                    Month(D) *= 10;
                    Month(D) += W.TabWord[i] - '0';
                    if (W.TabWord[i+1] == '/'){Q++;}
                    break;
                case 2:
                    Year(D) *= 10;
                    Year(D) += W.TabWord[i] - '0';
                    if (W.TabWord[i+1] == ' '){Q++;}
                    break;
                case 3:
                    Hour(Time(D)) *= 10;
                    Hour(Time(D)) += W.TabWord[i] - '0';
                    if (W.TabWord[i+1] == ':'){Q++;}
                    break;
                case 4:
                    Minute(Time(D)) *= 10;
                    Minute(Time(D)) += W.TabWord[i] - '0';
                    if (W.TabWord[i+1] == ':'){Q++;}
                    break;
                case 5:
                    Second(Time(D)) *= 10;
                    Second(Time(D)) += W.TabWord[i] - '0';
                    break;
                default: break;
            }
        }
    }
    return D;
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