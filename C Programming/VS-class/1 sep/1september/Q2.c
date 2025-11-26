#include <stdio.h>
#include <math.h>

int main() {
    double x, term, sum;
    int n = 1;
    printf("Enter value of x in radians: ");
    scanf("%lf", &x);

    term = x;
    sum = term;
    while (fabs(term) >= fabs(sum) * 0.000001) {
        term = -term * x * x / ((2 * n) * (2 * n + 1));
        sum += term;
        n++;
    }

    printf("cos(%.4lf) = %.10lf\n", x, sum);
    return 0;
// }