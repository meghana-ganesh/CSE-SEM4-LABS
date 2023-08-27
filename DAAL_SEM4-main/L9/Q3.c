#include<stdio.h>
#include<stdlib.h>

void search(int *hash_table)

void Closed_Hashing(int *arr,int n,int *hash_table)
{
    int m = n;
    for(int i=0;i<n;i++)
    {
        if(hash_table[arr[i] % m] != 0)
            //linear search for empty space
        else
            hash_table[arr[i] % m] = arr[i];
    }
}

int main()
{
    int n;
    printf("enter the no. of elements:");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    
    printf("\nenter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int *hash_table = (int*)malloc(n*sizeof(int));
    Closed_Hashing(arr,n,hash_tavle)
}