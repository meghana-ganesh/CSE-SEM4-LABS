#include<stdio.h>
int main()
{
    int m,n,t;
    printf("enter m and n:");
    scanf("%d %d",&m,&n);
    while(n != 0)
    {
        t = n;
        n = m%n;
        m = t;
    }
    printf("GCD is %d",m);
}