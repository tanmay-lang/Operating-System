#include<stdio.h>
#include<stdlib.h>


int secsmall(int a[],int n);    

void main()
{
    int n,a[25],sec;
    printf("enter no. of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sec=secsmall(a,n); 
    printf("Second Smallest: %d",sec);
}

int secsmall(int a[],int n)
{
    int i,small,secsmall;
    small=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<small)
        {
            small=a[i];
        }
    }
    if(a[0]==small)
    {
        secsmall=a[1];
    }
    else
    {
        secsmall=a[0];
    }
    for(i=1;i<n;i++)
    {
        if(a[i]>small && a[i]<secsmall)
        {
            secsmall=a[i];
        }
    }
    return secsmall;
}