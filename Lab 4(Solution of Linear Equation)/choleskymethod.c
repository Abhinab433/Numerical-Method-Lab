#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    float a[10][10],l[10][10],u[10][10],x[10],z[10],b[10],sum;
    int i=0,j=0,k=0,n;
    float temp = 0;
    printf("\nEnter dimension of matrix :: ");
    scanf("%d",&n);
    printf("\nEnter coefficients matrix :: ");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
   	 scanf("%f",&a[i][j]);
    
    printf("\nEnter RHS Vector :: ");
    for(i=0;i<n;i++)
   	 scanf("%f",&b[i]);
   		 
    //Calculating elements of U Matrix
    for(i=0;i<3;i++)
    {
   	 for(j=0;j<3;j++)
   	 {
   		 temp=0;
   		 if(i==j)
   		 {
   			 for(k=0;k<j;k++)
   			 {
   				 temp+=((u[k][i])*(u[k][i]));
   			 }
   			 u[i][i]=sqrt((a[i][i]-temp));
   		 }
   		 else if(j>i)
   		 {
   			 for(k=0;k<i;k++)
   			 {
   				 temp+=((u[k][i])*(u[k][j]));
   			 }
   			 u[i][j]=(1/(u[i][i]))*((a[i][j])-temp);
   		 }
   		 else
   			 u[i][j]=0;
   	 }
    }
    
    //Finding Transpose
    for(i=0;i<3;i++)
    {
   	 for(j=0;j<3;j++)
   	 {
   		 l[i][j]=u[j][i];
   	 }
    }
    
    printf("\n-----L Matrix-----\n");
    for(i=0;i<n;i++)
    {
   	 for(j=0;j<n;j++)
   		 printf("%g\t",l[i][j]);
   	 printf("\n");
    }
    
    printf("\n-----U Matrix-----\n");
    for(i=0;i<n;i++)
    {
   	 for(j=0;j<n;j++)
   		 printf("%g\t",u[i][j]);
   	 printf("\n");
    }

    //Solve for Z using Forward Substitution
    z[0]=b[0];
    for(i=1;i<n;i++)
    {
   	 for(j=0;j<i;j++)
   	 sum=sum+(l[i][j]*z[j]);
   	 z[i]=b[i]-sum;
   	 sum=0;
    }
    
    //Solve for X using Backward Substitution
    x[n-1]=z[n-1]/u[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
   	 for(j=i+1;j<n;j++)
   	 sum=sum+(u[i][j]*x[j]);
   	 x[i]=(z[i]-sum)/u[i][i];
   	 sum=0;
    }
    
    //Solution
    printf("\nSolution :: \n");
    for(i=0;i<n;i++)
    {
   	 printf("x[%d] = %g \n",i+1,x[i]);
    }
   		 
    getch();
    return 0;
}

