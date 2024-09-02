//to search an element in a dynamic array of n numbers.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, srcele, fnd = 0;
    printf("Element's total number in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &srcele);
    for (int i = 0; i < n; i++) {
        if (arr[i] == srcele) {
            printf("Element %d found at index %d\n", srcele, i);
            fnd = 1;
            break;
        }
    }
    if (!fnd) {
        printf("Element %d not found in the array\n",srcele );
    }
    free(arr);
return 0;
}
