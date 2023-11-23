#include <stdio.h>
#include <stdlib.h>
#include "kicauan/kicauan.h"
#include "datetime/datetime.h"


void fprintf_time(FILE *file, TIME T) {
    fprintf(file, " %02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

void fprintf_datetime(FILE *file, DATETIME D) {
    fprintf(file, "%d/%d/%d ", Day(D), Month(D), Year(D));
    fprintf_time(file, D.T);
    fprintf(file, "\n");
}

void save_balasan(ListKicauan LKicau) {
    FILE *file;
    int i, count = 0;
    addressTree p, q, r;
    file = fopen("file.txt", "w");

    for (int j = 0; j < listLength_ListKicauan(LKicau); j++) {
        if (Root(ListKicauan_ELMT(LKicau, i).Balasan) != NULL) {
            count++;
        }
    }
    fprintf(file, "%d\n", count);

    count = 0;

    for (i = 0; i < listLength_ListKicauan(LKicau); i++) {
        p = r = Root(ListKicauan_ELMT(LKicau, i).Balasan); // r always root
        if (p != NULL) {
            fprintf(file, "%d\n", i);
            while (p != NULL) {
                count++;
                p = LEFT(p);
                p = RIGHT(p);
            }
            fprintf(file, "%d\n", count);
            p = Root(ListKicauan_ELMT(LKicau, i).Balasan);
            while (p != NULL) {
                if (p == Root(ListKicauan_ELMT(LKicau, i).Balasan)) {
                    fprintf(file, "-1 %d\n", Id(p));
                }
                else {
                    q = getAddressBefore(r, p);
                    fprintf(file, "%d %d\n", Id(q), Id(p));
                }
                fprintf(file, *Pesan(p).TabWord, "\n", *User(p).TabWord, "\n");
                fprintf_datetime(file, Datetime(p));
                p = LEFT(p);
                p = RIGHT(p);
            }
            
        }
    }
}

