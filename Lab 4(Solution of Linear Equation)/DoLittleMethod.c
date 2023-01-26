#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n,i,j,k;
    float sum=0,a[10][10],b[10],x[10],z[10],u[10][10],l[10][10];
    printf("\nEnter dimension of Square Matrix :: ");
    scanf("%d",&n);
    printf("\nEnter coefficient matrix :: ");
    for(i=0;i<n;i++)
    {
   	 for(j=0;j<n;j++)
   	 
   		 scanf("%f",&a[i][j]);
    }
    
    printf("\nEnter RHS Vector :: ");
    for(i=0;i<n;i++)
    {
   	 scanf("%f",&b[i]);
    }
    
    //Computing Elements of L and U Matrix
    for(j=0;j<n;j++)
   	 u[0][j]= a[0][j];
    
    for(i=0;i<n;i++)
   	 l[i][i]=1;
    
    for(i=1;i<n;i++)
   	 l[i][0]=a[i][0]/u[0][0];
    
    for(j=1;j<n;j++)
    {
   	 for(i=1;i<=j;i++)
   	 {
   		 for(k=0;k<=i-1;k++)
   		 {
   			 sum=sum+(l[i][k]*u[k][j]);
   		 }
   		 u[i][j]=a[i][j]-sum;
   		 sum=0;
   	 }
    }
    
    for(i=j+1;i<n;i++)
    {
   	 for(k=0;k<=j-1;k++)
   	 {
   		 sum=sum+(l[i][k]*u[k][j]);
   	 }
   	 l[i][j]=(a[i][j]-sum)/u[j][i];
   	 sum=0;
    }
    
   printf("\n-----L Matrix-----\n");
   for(i=0;i<n;i++)
   {
  	 for(j=0;j<n;j++)
  	 {
  		 printf("\t%g",l[i][j]);
  	 }
  	 printf("\n");
   }
   
   printf("\n-----U Matrix-----\n");
   for(i=0;i<n;i++)
   {
  	 for(j=0;j<n;j++)
  	 {
  		 printf("\t%g",u[i][j]);
  	 }
  	 printf("\n");
   }

    //Solve for Z using Forward Substituion
    z[0]=b[0];
    for(i=1;i<n;i++)
    {
   	 for(j=0;j<n;j++)
   	 {
   		 sum=sum+(l[i][j]*z[j]);
   	 }
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
    
    printf("\nSolution :: \n");
    for(i=0;i<n;i++)
    {
   	 printf("x[%d] = %f\n",i+1,x[i]);
    }
   	 
    getch();
    return 0;
}

