#include <stdio.h>

double lagrangeInterpolation(double x, double xValues[], double yValues[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = yValues[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (x - xValues[j]) / (xValues[i] - xValues[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    int n;
    double x, xValues[100], yValues[100];
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the x-coordinates of the data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &xValues[i]);
    }
    printf("Enter the y-coordinates of the data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &yValues[i]);
    }
    printf("Enter the x-value at which you want to evaluate the polynomial: ");
    scanf("%lf", &x);

    printf("f(%.2lf) = %lf", x, lagrangeInterpolation(x, xValues, yValues, n));
    return 0;
}

