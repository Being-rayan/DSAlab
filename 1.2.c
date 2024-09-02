//reverse the elements of an array of a dynamic array of n elements
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
  
int* arr=(int*)malloc(n*sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n - i - 1] = temp;
    }
    printf("Reversed array:\n");
    for (int i = 0; i<n; i++) {
        printf("%d",arr[i]);
    }
    free(arr);
return 0;
}