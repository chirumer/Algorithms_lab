// sort numbers using bubble sort

#include <stdio.h>

int main() {
    
    int vals[100];
    int n;
    
    printf("Enter number of values: ");
    scanf("%d", &n);
    
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vals[i]);
    }
    
    // sorting
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            
            if (vals[j+1] < vals[j]) {
                int temp = vals[j];
                vals[j] = vals[j+1];
                vals[j+1] = temp;
            }
        }
    }
    
    printf("Values after sorting:");
    for (int i = 0; i < n; i++) {
        printf(" %d", vals[i]);
    }
    printf("\n");
    
    return 0;
}
