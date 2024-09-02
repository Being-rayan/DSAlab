/* store data of employee and calculate gross pay using structure.
Gross pay = basic pay + HR + DA 
HR=25% of basic and DA=75% of basic.*/

#include <stdio.h>

struct Employee {
    char name[100];
    char gender[10];
    char designation[100];
    char department[100];
    float bpay;
    float gpay;
};

void calcgpay(struct Employee* emp) {
    float HR = 0.25 * emp->bpay;
    float DA = 0.75 * emp->bpay;
    emp->gpay = emp->bpay + HR + DA;
}

int main() {
    int n, i;

    printf("Employee's total number: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]%*c", employees[i].name);  // using " %[^\n]%*c" to allow spaces in the name otherwise it will take only one name
        // or else we can write simply %s also for single word.
        printf("Gender: ");
        scanf(" %s", employees[i].gender);

        printf("Designation: ");
        scanf(" %[^\n]%*c", employees[i].designation);  

        printf("Department: ");
        scanf(" %[^\n]%*c", employees[i].department);  

        printf("Basic Pay: ");
        scanf("%f", &employees[i].bpay);

   
        calcgpay(&employees[i]);
    }

    printf("\nEmployee Details:\n");
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Gender: %s\n", employees[i].gender);
        printf("Designation: %s\n", employees[i].designation);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Pay: %.2f\n", employees[i].bpay);
        printf("Gross Pay: %.2f\n", employees[i].gpay);
    }

return 0;

}
