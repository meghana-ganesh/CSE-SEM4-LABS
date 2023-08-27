#include<stdio.h>
#include<stdlib.h>

void closed_hash(int *arr,int *hash_table,int h,int ind)
{
    int index = 0,flag = 0;
    
    for(int i=0;i<h;i++)
    {
        printf("%d ",hash_table[i]);
    }

    for(int i=0;i<ind;i++)
    {
        if(hash_table[arr[i] % h] != 0)
        {
            index = arr[i] % h;
            while(flag != 1)
            {
                index++;
                if(hash_table[index] == 0)
                    flag = 1;
                if(index == h)
                    index = 0;
            }
            hash_table[index] = arr[i];
        }
        else
            hash_table[arr[i] % h] = arr[i];
    }
}
 
int main()
{
    int h,x=1,ind = 0;
    printf("enter hash func:");
    scanf("%d",&h);
    int *arr = (int*)malloc(h*sizeof(int));
    int *hash_table = (int*)calloc(h,sizeof(int));
    printf("enter the elements of the array(-1) to exit:");

    while(1)
    {
        scanf("%d",&x);
        if(x == -1)
            break;
        else
            arr[ind++] = x;
    }
    for(int i=0;i<ind;i++)
    {
        printf("%d ",arr[i]);
    }
    closed_hash(arr,hash_table,h,ind);
    printf("\n");
    for(int i=0;i<h;i++)
    {
        printf("%d ",hash_table[i]);
    }
}

// 31 63 27 19    h:11
// 9  8   5  8 

//20 25 36 47 58 69
//0   0  1  2  3  4
