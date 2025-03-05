#include<stdio.h>
#include<stdlib.h>

int sumlftdia(int a[25][25],int m,int n);

void main()
{
    int a[25][25],m,n,sum;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d %d",&m,&n);
    printf("Enter matrix ele:");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    sum=sumlftdia(a,m,n);
    printf("Sum of left diagonal elements is %d",sum);
}

int sumlftdia(int a[25][25],int m,int n)
{
    int sum=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum=sum+a[i][j];
            }
        }
    }
    return sum;
}