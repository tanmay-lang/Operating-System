#include<stdio.h>
#include<stdlib.h>


int seclarg(int a[],int n);    

void main()
{
    int n,a[25],sec;
    printf("enter no. of elements:");
    scanf("%d",&n);
    printf("Enter elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sec=seclarg(a,n); 
    printf("Second Largest: %d",sec);
}

int seclarg(int a[],int n){
    int i,large,seclarge;
    large=a[0];
    for(i=1;i<n;i++){
        if(a[i]>large){
            large=a[i];
        }
    }
    if(a[0]==large){
        seclarge=a[1];
    } else {
        seclarge=a[0];
    }
    for(i=1;i<n;i++){
        if(a[i]<large && a[i]>seclarge){
            seclarge=a[i];
        }
    }
    return seclarge;
}