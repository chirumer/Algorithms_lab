// to search an integer using linear search

#include <stdio.h>

int main() {
    
    int n;
    printf("Enter number of values: ");
    scanf("%d", &n);
    
    int vals[100];
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }
    
    int srch;
    printf("Enter search element: ");
    scanf("%d", &srch);
    
    for (int i = 0; i < n; i++) {
        if (vals[i] == srch) {
            printf("Element found at %dth position", i+1);
            return 0;
        }
    }
    printf("Element not found.");
    return 0;
}
