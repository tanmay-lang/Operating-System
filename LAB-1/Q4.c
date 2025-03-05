#include<stdio.h>
#include<stdlib.h>

int totaldup(int a[],int n);

void main()
{
    int a[25],n,td;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    td=totaldup(a,n);
    printf("No. of duplicate numbers are:%d",td);
}

int totaldup(int a[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
   {
    for(int j=i+1;j<n;j++)
    {
        if(a[i]==a[j])
        {
            count++;
        
        }
    }
   }
   return count;
}