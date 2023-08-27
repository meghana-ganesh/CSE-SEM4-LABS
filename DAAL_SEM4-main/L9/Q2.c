#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initialize(int **hash_table,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            hash_table[i][j] = 0;
        }
    }

}

void Open_Hashing(int *arr,int **hash_table,int n)
{
    initialize(hash_table,n);
    int m = n;
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(hash_table[arr[i] % m][0] != 0)
            hash_table[arr[i]%m][++k] = arr[i];
        else
            hash_table[arr[i] % m][0] = arr[i];
    }
    for(int i= 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(hash_table[i][j] != 0 || j == 0)
                printf("%d ",hash_table[i][j]);
        }
        printf("\n");
    }
}

void search(int **hash_table,int n,int key)
{
    int i = key % n;
    for(int j=0;j<n;j++)
    {
        if(hash_table[i][j] == key)
        {
            printf("element found");
            return;
        }
    }
    printf("element not found");
}

int main()
{
    int n;
    printf("enter the mod function:");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    
    printf("\nenter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int **hash_table = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        hash_table[i] = (int*)malloc(n*sizeof(int));
    }

    Open_Hashing(arr,hash_table,n);
    search(hash_table,n,63);
}