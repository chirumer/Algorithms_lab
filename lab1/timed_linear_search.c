// time taken for executing linear search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define size 1000000

bool linear_search(int arr[], int sze, int srch) {
    for (int i = 0; i < sze; i++) {
        if (arr[i] == srch) {
            return true;
        }
    }
    return false;
}

int main() {
    
    srand(time(NULL));
    
    int vals[size];
    for (int i = 0; i < size; i++) {
        vals[i] = rand();
    }
    
    for (int i = 10; i <= size; i *= 10) {
        int srch = rand();
        clock_t start = clock();
        linear_search(vals, i, srch);
        clock_t stop = clock();
        
        double time_taken = (double)(stop-start)/CLOCKS_PER_SEC;
        printf("time taken for %d elements: %lf milliseconds\n", i, time_taken*1000);
    }
    
    return 0;
}
