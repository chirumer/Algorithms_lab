// compare times taken for linear search and binary search

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 100000

bool linear_search(int elements[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (elements[i] == search) {
            return true;
        }
    }
    return false;
}

bool binary_search(int elements[], int n, int search) {
    int start = 0, end = n-1;
    
    while (start <= end) {
        int middle = (start + end) / 2;
        if (elements[middle] == search) {
            return true;
        }
        else if (search < elements[middle]) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
    
    return false;
}

int main() {
    
    srand(time(0));
    
    while (true) {
    
        int n;
        printf("Enter value of N: ");
        scanf("%d", &n);
    
        int elements[SIZE];
        for (int i = 0; i < n; i++) {
            elements[i] = rand();
        }
    
        int search_element = rand();
    
        clock_t start, end;
        double time_taken;
    
        start = clock();
        for (int i = 0; i < 100000; i++) {
            linear_search(elements, n, search_element);
        }
        end = clock();
        time_taken = (end - start)/(double)CLOCKS_PER_SEC * 1000;
        printf("Time taken for 1000 linear searches with %d elements: %lf milliseconds\n", n, time_taken);
    
    
        start = clock();
        for (int i = 0; i < 100000; i++) {
            binary_search(elements, n, search_element);
        }
        end = clock();
        time_taken = (end - start)/(double)CLOCKS_PER_SEC * 1000;
        printf("Time taken for 1000 binary searches with %d elements: %lf milliseconds\n", n, time_taken);
    }
    
    return 0;
}
