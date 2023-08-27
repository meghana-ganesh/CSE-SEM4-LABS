#include<stdio.h>
#include<stdlib.h>

void copy(int *A,int l,int u,int *B,int *x)
{
    for(int i=l;i<u;i++)
    {
        B[*x] = A[i];
        (*x)++;
    }
}

void merge(int *B,int *C,int *A,int p,int q)
{
    int i=0,j=0;
    int k = 0;
    while(i < p && j < q)
    {
        if(B[i] <= C[j])
        {
            A[k] = B[i];
            i = i + 1;
        }
        else
        {
            A[k] = C[j];
            j = j + 1;
        }
        k = k + 1;
    }
    if(i == p)
        copy(C,j,q,A,&k);
    else
        copy(B,i,p,A,&k);
}


void mergesort(int *A,int n)
{
    if(n>1)
    {
        int *B = (int*)malloc(n*sizeof(int));
        int *C = (int*)malloc(n*sizeof(int));
        int p = 0,q = 0;
        copy(A,0,(n/2),B,&p);
        copy(A,(n/2),n,C,&q);
        mergesort(B,p);
        mergesort(C,q);
        merge(B,C,A,p,q);
    }
}

int main()
{
    int n;
    int p=0;
    printf("enter the no. of elements:");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("\nenter the elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
   
    mergesort(arr,n);
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    
}