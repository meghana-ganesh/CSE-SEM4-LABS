#include<stdio.h>
#include<stdlib.h>


void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void permute(int **mat,int n,int *indexArr,int l,int r,int *cost,int *minCost)
{
    if(l == r)
    {
        printf("\nhi");
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+= mat[i][indexArr[i]];
        }
        
        if(sum<*cost)
        {
            *cost = sum;
            printf("\ncost:%d ",*cost);
        }
    }
    else
    {
        printf("ji");
        for(int i=l;i<=r;i++)
        {
            swap(&indexArr[l],&indexArr[i]);
            permute(mat,n,indexArr,l+1,r,&cost);
            //backtrack
            swap(&indexArr[l],&indexArr[i]);
        }
    }
}

int main()
{
    int n;
    printf("enter no. of employees and jobs:");
    scanf("%d",&n);
    int **mat = (int **)malloc(n*sizeof(int*));
    int *indexArr = (int*)malloc(n*sizeof(int));


    for(int i=0;i<n;i++)
    {
        mat[i] = (int*)malloc(n*sizeof(int));
        indexArr[i] = i;
    }

    int cost = 1000;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("\nenter no. of hours worked by employee %d for job %d:",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

    permute(mat,n,indexArr,0,n-1,&cost);
}