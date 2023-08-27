#include <stdio.h>
#include <stdlib.h>

void input(int *arr,int n,int *opc)
{
    printf("\nenter the elements:");
    for(int i=0;i<n;i++)
    {
        (*opc)++;
        scanf("%d",&arr[i]);
    }
}


void bubbleSort(int *arr, int n,int *opc) 
{
    int temp;
    int flag = 0;
    for (int i=0; i < n-1; i++) 
    {
        (*opc)++;
        flag = 0;
        for (int j=0; j < n-i-1; j++) 
        {
            (*opc)++;
            if(arr[j] > arr[j+1]) 
            {
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\nflag:%d",flag);
}

void display(int *arr,int n,int *opc)
{
    for(int i=0;i<n;i++)
    {
        (*opc)++;
        printf("%d ",arr[i]);
    }
}

int main()
{
    int n;
    int opc=0;
    printf("\nenter no. of elements in the array:");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    input(arr,n,&opc);
    bubbleSort(arr,n,&opc);
    printf("\n");
    display(arr,n,&opc);
    printf("\nopc:%d",opc);
    return 0;
}