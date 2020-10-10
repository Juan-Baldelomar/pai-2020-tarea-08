#include "./heap.c"
#include "median.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandom(int base, int limit) {
    return base + rand() % (limit - base + 1);
}

int test_insert_element(void){
    printf("Al probar un elemento se debe mantener la propiedad del heap: ");
    // Create heap
    // add 0
    // if(getMax(th) != 0){puts("ERROR"); return 0;}

    // add 1
    // if(getMax(th) != 1){puts("ERROR"); return 0;}

    // add 5
    // if(getMax(th) != 5){puts("ERROR"); return 0;}

    // add 3
    // if(getMax(th) != 5){puts("ERROR"); return 0;}

    int resultado = 1;
    //if(resultado != 0){puts ("ERROR"); return 0;}

    puts("OK");
    return 1;
}

int testMinHeap() {
    srand(time(0));
    THeap *h = createTHeap(100);
    int status = 1;
    printf("testing resize heap too\n");
    for (int i = 0; i < 200; i++) {
        int data = getRandom(0, 200);
        //printf("%d ", data);
        minHeapInsert(h, data);
    }
    //printf("\n");
    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    //printf("max: %d\n", getMin(h));
    removeMin(h);

    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    removeMin(h);

    status &= verifyMinHeapProperty(h);
    //printHeap(h);

    return status;
}

int testMaxHeap() {
    srand(time(0));
    THeap *h = createTHeap(100);
    int status = 1;

    printf("testing resize heap too\n");
    for (int i = 0; i < 200; i++) {
        int data = getRandom(0, 200);
        insert(h, data);
    }

    status &= verifyHeapProperty(h);

    removeMax(h);

    status &= verifyHeapProperty(h);

    removeMax(h);

    status &= verifyHeapProperty(h);

    return status;
}



int main(int num_args, char ** args){
    printf("INIT TESTS\n");
    int all_tests_ok = 1;
    all_tests_ok &= testMinHeap();
    all_tests_ok &= testMaxHeap();
    all_tests_ok &= test_insert_element();
    assert(all_tests_ok);
    return 0;
}
