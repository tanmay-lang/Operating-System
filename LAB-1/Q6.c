#include<stdio.h>
#include<stdlib.h>

void del(int a[],int pos);
void display(int a[]);
int n;

void main()
{
int a[25]={},pos;
    printf("enter no. of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter position to be deleted:");
    scanf("%d",&pos);
    del(a,pos);
    display(a);

}    

void del(int a[],int pos)
{
    if(pos>=n)
    {
        printf("OUt of bounds ");
        return;
    }
    for(int i=pos+1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    n--;
    printf("Successfully removed\n");
}

void display(int a[])
{
    printf("Array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
