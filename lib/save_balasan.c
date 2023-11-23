#include <stdio.h>
#include <stdlib.h>
#include "kicauan/kicauan.h"
#include "datetime/datetime.h"

int countElmtTree(addressTree p) {
    if (p != NULL) {
        return 1 + countElmtTree(FirstChild(p)) + countElmtTree(NextSibling(p));
    }
}

void displayBalasan(FILE *file, addressTree p, addressTree root, ListKicauan LKicau, int i) {
    addressTree q;
    if (p != NULL) {
        if (p == Root(ListKicauan_ELMT(LKicau, i).Balasan)) {
            fprintf(file, "-1 %d\n", Id(p));
        }
        else {
            q = getAddressBefore(root, p);
            fprintf(file, "%d %d\n", Id(q), Id(p));
        }
        for (int k = 0; k < Pesan(p).Length; k++) {
            fprintf(file, "%c", Pesan(p).TabWord[k]);
        }
        fprintf(file, "\n");
        for (int k = 0; k < User(p).Length; k++) {
            fprintf(file, "%c", User(p).TabWord[k]);
        }
        fprintf(file, "\n");
        TulisDATETIMEFILE(Datetime(p), file);
        displayBalasan(file, FirstChild(p), root, LKicau, i);
        displayBalasan(file, NextSibling(p), root, LKicau, i);
    }
}

void save_balasan(ListKicauan LKicau) {
    FILE *file;
    int i, count = 0;
    addressTree p, q, r;
    file = fopen("file.txt", "w");

    printf("%d\n", count);
    for (int j = 0; j < listLength_ListKicauan(LKicau); j++) {
        if (Root(ListKicauan_ELMT(LKicau, j).Balasan) != NULL) {
            count++;
        }
    }
    printf("%d\n", count);
    if (count == 0) {
        fprintf(file, "%d", count);
    }
    else {
        fprintf(file, "%d\n", count);
    }


    for (i = 0; i < listLength_ListKicauan(LKicau); i++) {
        p = r = Root(ListKicauan_ELMT(LKicau, i).Balasan); // r always root
        if (p != NULL) {
            fprintf(file, "%d\n", i+1);
            count = countElmtTree(p);
            fprintf(file, "%d\n", count);
            displayBalasan(file, p, r, LKicau, i);
        }
    }
    fclose(file);
}

