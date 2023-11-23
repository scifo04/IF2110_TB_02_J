#include <stdio.h>
#include "temanreq.h"
#include "../wordmachine/wordmachine.h"
#include "../wordmachine/charmachine.h"

int main() {
    Address a;
    ELFRType b,c,d;
    ELFRType junk;
    b.idRequested = 0;
    b.idRequester = 1;
    b.popularity = 3;
    c.idRequested = 1;
    c.idRequester = 2;
    c.popularity = 4;
    d.idRequested = 2;
    d.idRequester = 3;
    d.popularity = 2;
    a = newRequest(b);
    QueueFR q;
    CreateQueueFR(&q);
    int r;
    scanf("%d",&r);
    switch(r) {
        case 1:
            if (isEmptyQueueFR(q)) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 2:
            enQueueFR(&q,b);
            enQueueFR(&q,c);
            int len = length_QueueFR(q);
            if (len == 2) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
            break;
        case 3:
            enQueueFR(&q,b);
            enQueueFR(&q,c);
            enQueueFR(&q,d);
            displayQueueFR(q);
            printf("\n");
            break;
        case 4:
            enQueueFR(&q,b);
            enQueueFR(&q,c);
            enQueueFR(&q,d);
            deQueueFR(&q,&junk);
            boolean condition = junk.idRequested == c.idRequested && junk.idRequester == c.idRequester && junk.popularity == c.popularity;
            if (condition) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
        case 5:
            enQueueFR(&q,b);
            enQueueFR(&q,c);
            enQueueFR(&q,d);
            int find = indexOfQueueFR(q,1);
            if (find == b.idRequester) {
                printf("TRUE\n");
            } else {
                printf("FALSE\n");
            }
    }

    return 0;
}
