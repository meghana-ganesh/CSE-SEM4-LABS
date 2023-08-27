#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *arr, int n, int l, int u)
{
    if (l >= u)
        return;
    int pivot = arr[l];
    int i = l + 1;
    int j = u;
    while (i <= j)
    {
        while (i <= u && arr[i] < pivot) 
        {
            i++;
        }
        while (j >= l + 1 && arr[j] > pivot) 
        {
            j--;
        }
        if (i <= j) 
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[l], &arr[j]);
    quicksort(arr, n, l, j - 1);
    quicksort(arr, n, j + 1, u);
}


int main()
{
    int n;
    printf("enter the no. of elements:");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    quicksort(arr,n,0,n-1);
    printf("\nsorted array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}