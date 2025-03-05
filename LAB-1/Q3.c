#include<stdio.h>
#include<stdlib.h>

void  sumrc(int a[25][25],int m,int n);

void main()
{
    int a[25][25],m,n,s;
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
    sumrc(a,m,n);
 
}

void sumrc(int a[25][25],int m,int n)
{
    int rowsum=0,colsum=0;
    for(int i=0;i<m;i++)
    {
        rowsum=0,colsum=0;
        for(int j=0;j<n;j++)
        {
            rowsum=rowsum+a[i][j];
            colsum=colsum+a[j][i];
        
        }
        printf("Sum of row %d is %d\n",(i+1),rowsum);
        printf("Sum of column %d is %d\n",(i+1),colsum);
    }
}