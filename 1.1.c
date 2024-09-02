// find the smallest and largest number in an array
#include<stdio.h>
int main () {
    
int arr[10],i,min,max;
printf("enter the elements of array:");
for(i=0;i<10;i++) {
scanf("%d",&arr[i]);
}
min = max = arr[0];
    for(i = 1; i < 10; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
     printf("Minimum element is: %d\n", min);
    printf("Maximum element is: %d\n", max);
return 0;
}