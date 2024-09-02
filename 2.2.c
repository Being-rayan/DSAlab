// add two distances (in km-meter) by passing structure to a function.

#include <stdio.h>
struct dist {
    float km;
    float met;
};
void addDist(struct dist d1, struct dist d2, struct dist *d3) {
    d3->km = d1.km + d2.km;
    d3->met = d1.met + d2.met;
    // Convert meters to kilometers if meters exceed 1000
    if (d3->met >= 1000) {
        d3->km += (int)(d3->met / 1000);
        d3->met = (int)d3->met % 1000;
    }
}
int main() {
    struct dist D1, D2, D3;
    
    printf("Enter the distance in Kilometers and Meters for D1: ");
    scanf("%f %f", &D1.km, &D1.met);
    printf("Enter the distance in Kilometers and Meters for D2: ");
    scanf("%f %f", &D2.km, &D2.met);

    addDist(D1, D2, &D3);
    printf("Sum of the distances: %.2f km and %.2f meters\n", D3.km, D3.met);
    return 0;
}