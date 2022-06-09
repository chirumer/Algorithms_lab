// Comparison: recursive linear serach and recursive binary search

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 1000000

int linear_srch(int a[], int siz, int srch) {
    if (siz == 0) {
        return -1;
    }
    if (a[siz - 1] == srch) {
        return siz - 1;
    }
    return linear_srch(a, siz - 1, srch);
}

int binary_srch(int a[], int srch, int lowr, int uppr) {
    if (lowr > uppr) {
        return -1;
    }
    int middl = (lowr+uppr)/2;
    if (a[middl] == srch) {
        return middl;
    }
    if (srch < a[middl]) {
        return binary_srch(a, srch, lowr, middl - 1);
    }
    else {
        return binary_srch(a, srch, middl + 1, uppr);
    }
}

void bubble_sort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {

    srand(time(0)); // initialize rand()
    
    int choice;
    
    do {
        printf("(1) Linear Search\n"
               "(2) Binary Search\n"
               "(3) Exit\n"
               "--> ");
        scanf("%d", &choice);
        
        if (choice == 3) {
            break;
        }
        
        int N;
        printf("Enter number of elements to generate (max is: %d)\n--> ", MAX_SIZE);
        scanf("%d", &N);
        
        int elems[MAX_SIZE];
        for (int i = 0; i < N; i++) {
            elems[i] = rand();
        }
        if (choice == 2) {
            bubble_sort(elems, N);
        }
        int srch = rand();
    
        const int NUM_OF_ITERATIONS = 10000;
        clock_t start = clock();
        if (choice == 1) {
            for (int i = 0; i < NUM_OF_ITERATIONS; i++) {
                linear_srch(elems, N, srch);
            }
        }
        else if (choice == 2) {
            for (int i = 0; i < NUM_OF_ITERATIONS; i++) {
                binary_srch(elems, srch, 0, N - 1);
            }
        }
        clock_t end = clock();
        
        double time_taken = ((end - start)/(double)CLOCKS_PER_SEC) * 1000;
        printf("Time taken for %d iterations: | %lf milliseconds |\n", NUM_OF_ITERATIONS, time_taken);
        
    } while (choice != 3);
    
    return 0;
}
