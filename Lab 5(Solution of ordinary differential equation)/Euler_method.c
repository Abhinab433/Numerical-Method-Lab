#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x,y) 2*y/x //insert function here


int main()
{
    float x,xp,x0,y0,y,h;
    printf("\nEnter initial values of x & y :: ");
    scanf("%f %f",&x0,&y0);
    printf("\nEnter x at which the function is to be evaluated :: ");
    scanf("%f",&xp);
    printf("\nEnter step size :: ");
    scanf("%f",&h);
    y=y0;
    x=x0;
    for(x=x0;x<xp;x=x+h)
    {
   	 y=y+f(x,y)*h;
    }
    printf("\nFunction value at x = %f is %f. ",xp,y);
    getch();
    return 0;
}

