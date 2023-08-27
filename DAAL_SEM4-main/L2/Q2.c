#include<stdio.h>
#include<stdlib.h>

int isPrime(int x,int *opc)
{
    int count = 0;
    for(int i=2;i<x+1;i++)
    {
        (*opc)++;
        if(x%i == 0)
        {
            count++;
        }
    }
    if(count == 1)
        return 1;
    else 
        return 0;
}

void primefactorization(int *exp,int *cst,int m,int *k,int *opc)
{
    int count=0;
    for(int i=2;i<m+1;i++)
    {
        (*opc)++;
        int n = m;
        if(isPrime(i,opc)==1 && (m%i)==0)
        {
            while((n%i) == 0)
            {
                (*opc)++;
                count++;
                n = (float)n/i;
                // printf("n:%d\n",n);
            }
        }
        if(count>0)
        {
            // printf("count:%d\n",count);
            cst[*k] = i;
            // printf("i:%d\n",i);
            exp[*k] = count;
            (*k)++;
            count = 0;
        }
        else
        {
            count = 0;
        }
    }
}

int gcd_middle_school(int *exp1,int *cst1,int *exp2,int *cst2,int *k,int *l,int *opc)
{
    int a = 1;
    int prod = 1;
    for(int i=0;i<*k;i++)
    {
        (*opc)++;
        for(int j=0;j<*l;j++)
        {
            (*opc)++;
            if(cst1[i] == cst2[j])
            {
                if(exp1[i]<exp2[j] || exp1[i] == exp2[j])
                {
                    prod *= cst1[i] * exp1[i];        
                }
                else
                {
                    prod *= cst1[i] * exp2[i];
                }
            }
        }
    }
    return prod;
}


int main()
{
    int *cst1;
    int *exp1;
    int *cst2;
    int *exp2;
    int k = 0;
    int l = 0;
    int m,n;
    int opc = 0;

    cst1 = (int*)malloc(20*sizeof(int));
    exp1 = (int*)malloc(20*sizeof(int));
    cst2 = (int*)malloc(20*sizeof(int));
    exp2 = (int*)malloc(20*sizeof(int));
    printf("enter m and n:");
    scanf("%d %d",&m,&n);
    primefactorization(exp1,cst1,m,&k,&opc);
    primefactorization(exp2,cst2,n,&l,&opc);
    printf("GCD is:%d\n",gcd_middle_school(exp1,cst1,exp2,cst2,&k,&l,&opc));
    // for(int i=0;i<k;i++)
    // {
    //     printf("%d^%d ",cst1[i],exp1[i]);
    // }
    printf("opc:%d",opc);
    return 0;
}