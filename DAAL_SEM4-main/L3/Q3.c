#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void input(int *arr,int n)
{
    printf("\nenter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

}

void possible_sets(int *arr,int n,int *key)
{

    int pow_set_size = pow(2,n);
    int count = 0;
    int j = 0;
    int k;
    int n_sets=0;

    int *subs = (int*)malloc(n*sizeof(int));


    for(count=0;count<pow_set_size;count++)
    {

        int sum = 0;
        k = 0;
        for(j=0;j<n;j++)
        {
            if(count & 1<<j)
            {
                subs[k] = arr[j];
                k++;
                sum += arr[j];
            }
        }
        if(sum == *key)
        {
            n_sets++;
            for(int x=0;x<k;x++)
            {
                printf("%d ",subs[x]);
            }
            printf("\n");
            if(n_sets == 2)
            {
                printf("partitioning is possible.");
                return;
            }
        }
    }
    printf("partitioning is not possible.");
    
}


int main()
{
    int n;
    int k=0;
    int l=0;

    printf("\nenter no. of elements in the array:");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    input(arr,n);


    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int key = (float)sum/2;


    possible_sets(arr,n,&key);
    
}