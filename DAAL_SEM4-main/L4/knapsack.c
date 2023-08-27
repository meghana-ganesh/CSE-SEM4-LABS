#include<stdio.h>
#include<stdlib.h>
#include<math.h>



void knapsack_soln(int *wt,int *val,int n,int capacity)
{
    int pow_set_size = pow(2,n);
    int max_val = 0;

    for(int i=0;i<pow_set_size;i++)
    {
        int total_wt=0;
        int total_val=0;

        for(int j=0;j<n;j++)
        {
            if(i & 1<<j)
            {
                total_wt += wt[j];
                total_val += val[j];
            }
        }
        if(total_wt <=capacity && total_val>max_val)
        {

        }
    }

}


int main()
{
    int n,capacity;
    int *wt,*val;

    printf("enter the no. of items:");
    scanf("%d",&n);

    wt = (int*)malloc(n*sizeof(int));
    val = (int*)malloc(n*sizeof(int));

    printf("\nenter the weights of items:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&wt[i]);
    }

    printf("\nenter the values of items:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&val[i]);
    }
    printf("\nenter the max capacity:");
    scanf("%d",&capacity);

    knapsack_soln(wt,val,n,capacity);

}