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

void possible_sets(int *arr,int n,int *subs,int *k,int *sets,int *l)
{
    int pow_set_size = pow(2,n);
    int count = 0;
    int j = 0;
    for(count=0;count<pow_set_size;count++)
    {
        subs[*k] = 0;
        for(j=0;j<n;j++)
        {
            if(count & 1<<j)
            {
                sets[*l] = arr[j];
                (*l)++;
                subs[*k] += arr[j];
            }
        }
        sets[*l] = -1;
        (*l)++;
        (*k)++;
    }
    printf("sum of all sets:");
    for(int i=0;i<*k;i++)
    {
        printf("%d ",subs[i]);
    }
    printf("\npossible subsets:");
    for(int i=0;i<*l;i++)
    {
        printf("%d ",sets[i]);
    }
}


int partition_soln(int *arr,int n,int *subs,int *k,int *sets,int *l)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    int key = (float)sum/2;
    int flag = 0;
    // printf("\nkey:%d",key);
    for(int i=0;i<*k;i++)
    {
        if(key == subs[i])
        {
            flag+=1;
        }
    }
    
    return flag;
}
// 1 5 5 11
int main()
{
    int n;
    int k=0;
    int l=0;

    printf("\nenter no. of elements in the array:");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    int *subs = (int*)malloc(n*sizeof(int));
    int *sets = (int*)malloc(100*sizeof(int));
    
    input(arr,n);
    possible_sets(arr,n,subs,&k,sets,&l);
    if(partition_soln(arr,n,subs,&k,sets,&l) >= 2)
        printf("\ntrue");
    else 
        printf("\nfalse");
}