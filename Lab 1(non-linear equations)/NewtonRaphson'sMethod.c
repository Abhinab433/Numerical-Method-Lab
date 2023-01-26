#include <stdio.h>
#include <math.h>
#define f(x) (x*x*x + 5*x - 3)
#define derivative(x) (3*x*x + 5)
int main()
{
    int itr = 1;
    float h, x0, x1, err;
    printf("\nEnter initial condition x0: ");
    scanf("%f", &x0);
    printf("Enter Error precision: ");
    scanf("%f", &err);
    printf("\n");
    while(1){
        h = f(x0) / df(x0);
        x1 = x0 - h;
        printf("At Iteration no. %d, x = %9.6f\n", itr, x1);
        if (fabs(h) < err){
            printf("After %d iterations, root = %8.6f\n", itr, x1);
            return 0;
        }
        x0 = x1;
        itr++;
    }
    return 0;
}

