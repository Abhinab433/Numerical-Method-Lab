#include <stdio.h>
#include <math.h>
float fun(float x){
    return (3 * x * x - 6 * x + 2);
}
void bisection(float *x, float a, float b, int *itr){
    *x = (a + b) / 2;
    ++(*itr);
    printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}
int main()
{
    int itr = 0, maxmitr;
    float x, a, b, allerr = 0.1, x1;
    printf("\nEnter the values of a, b and maximum iterations:\n");
    scanf("%f %f %d", &a, &b, &maxmitr);
    bisection(&x, a, b, &itr);
    do
    {
        if (fun(a) * fun(x) < 0)
            b = x;
        else
            a = x;
            
        bisection(&x1, a, b, &itr);
        if (fabs(x1 - x) < allerr){
            printf("After %d iterations, root = %6.4f\n", itr, x1);
            return 0;
        }
        x = x1;
    } while (itr < maxmitr);
    printf("The solution does not converge or iterations are not sufficient");
    return 1;
}

