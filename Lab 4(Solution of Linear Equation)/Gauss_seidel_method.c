//Solving Linear Equations with Gauss-Seidel Iteration Method
#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int n,i,j,k;
    float sum,error,E[10],a[10][10],b[10],new_x[10],old_x[10];
    printf("\nEnter Dimension of System of Equations :: ");
    scanf("%d",&n);
    printf("\nEnter coefficient matrix :: ");
    for(i=0;i<n;i++)
    {
   	 for(j=0;j<n;j++)
   		 scanf("%f",&a[i][j]);
    }
    printf("\nEnter B vector :: ");
    for(i=0;i<n;i++)
    {
   	 scanf("%f",&b[i]);
    }
    printf("\nEnter accuracy limit :: ");
    scanf("%f",&error);
    
    for(i=0;i<n;i++)
   	 new_x[i]=0;
    
    while(1)
    {
   	 for(i=0;i<n;i++)
   	 {
   		 sum=b[i];
   		 for(j=0;j<n;j++)
   		 {
   			 if(i!=j)
   				 sum=sum-a[i][j]*new_x[j];
   		 }
   		 old_x[i]=new_x[i];
   		 new_x[i]=sum/a[i][i];
   		 E[i]=fabs(new_x[i]-old_x[i])/fabs(new_x[i]);
   	 }
   	 for(i=0;i<n;i++)
   	 {
   		 if(E[i]>error)
   			 break;
   	 }
   	 if(i==n)
   		 break;
   	 else
   		 continue;
    }
    
    printf("\nSolution :: \n");
    for(i=0;i<n;i++)
   	 printf("\nX[%d] = %g ",i+1,new_x[i]);
   	 
    getch();
    return 0;
}

