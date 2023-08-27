#include<stdio.h>
#include<stdlib.h>
void display(int **mat,int n,int w)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
int max(int a,int b)
{
    if(a >= b)
        return a;
    else
        return b;
}

void createmat(int **mat,int n,int w,int *values,int *weights)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            mat[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j = 1;j<w+1;j++)
        {
            if(j - weights[i] >=0)
            {
                mat[i][j] = max(mat[i-1][j],values[i] + mat[i-1][j-weights[i]]);
            }
            else
            {
                mat[i][j] = mat[i-1][j];
            }
        }
    }

}

void optimalsoln(int **mat,int n,int w,int *weights)
{
    int optimalset[10];
    int k=0;
    int start = mat[n][w];
    int i=n;
    int j = w;
    while(i != 0)
    {
        if(mat[i][j] != mat[i-1][j])
        {
            optimalset[k++] = i;
            j = j - weights[i];
            i--;
        }
        else
        {
            i--;
        }
    }
    for(int i=0;i<k;i++)
    {
        printf("%d ",optimalset[i]);
    }
}

int main()
{
    int n,w;
    printf("enter n and w:");
    scanf("%d %d",&n,&w);
    int *values = (int*)malloc((n+1)*sizeof(int));
    int *weights = (int*)malloc((n+1)*sizeof(int));
    int **mat = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0;i<n+1;i++)
    {
        mat[i] = (int*)malloc((w+1)*sizeof(int));
    }


    
    printf("enter weights array:");
    for(int i=1;i<n+1;i++)
    {
        scanf("%d",&weights[i]);
    }
    printf("enter values array:");
    for(int i=1;i<n+1;i++)
    {
        scanf("%d",&values[i]);
    }
    
    createmat(mat,n,w,values,weights);
    display(mat,n,w);
    optimalsoln(mat,n,w,weights);
    
}