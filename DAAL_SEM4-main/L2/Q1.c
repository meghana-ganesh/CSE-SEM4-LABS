#include<stdio.h>
int main()
{
    int m,n,t;
    int opc = 0;
    printf("enter m and n:");
    scanf("%d %d",&m,&n);
    if(m>n)
        t = n;
    else
        t = m;
    while(t != 0)
    {
        (opc++);
        if(m % t == 0)
        {
            if(n % t == 0)
            {
            printf("GCD is %d\n",t);
            break;;
            }
        }
        t = t-1;
    }
    printf("opc:%d",opc);
}