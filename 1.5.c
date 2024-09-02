// Function to find and display elements between a and b (inclusive).
#include <stdio.h>
#include <stdlib.h>
void findElementsBetween(int *arr, int n, int a, int b) {
    int count = 0;
    printf("The numbers between %d and %d (inclusive) are: ", a, b);
    
    for (int i = 0; i < n; i++) {
        if (arr[i] >= a && arr[i] <= b) {
            printf("%d ", arr[i]); 
            count++;
        }
    }
    printf("\nTotal count: %d\n", count); 
}

int main() {
    int n, a, b;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    findElementsBetween(arr, n, a, b);

    free(arr);

    return 0;
}
