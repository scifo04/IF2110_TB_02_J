#include <stdio.h>
#include <stdlib.h>
#include "implementasiadt.h"

int main() {
    ListStatik l;
    readList_ListStatik(&l);
    printList_ListStatik(l);
    return 0;
}