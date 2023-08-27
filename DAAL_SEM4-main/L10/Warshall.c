#include<stdio.h>
#include<stdlib.h>

void display(int **mat,int v)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void warshalls(int **mat,int v)
{
    for(int k=0;k<v;k++)
    {
        for(int j=0;j<v;j++)
        {
            for(int i=0;i<v;i++)
            {
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }
}


int main()
{
    int v,ans;
    printf("enter the no. of vertices:");
    scanf("%d",&v);
    int **mat = (int**)malloc(v*sizeof(int*));
    for(int i=0;i<v;i++)
    {
        mat[i] = (int*)malloc(v*sizeof(int));
    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            printf("does %d have a connection with %d(0/1)?",i+1,j+1);
            scanf("%d",&ans);
            if(ans == 1)
                mat[i][j] = 1;
            else
                mat[i][j] = 0;
        }
    }
    display(mat,v);
    printf("after applying warshalls:\n");
    warshalls(mat,v);
    display(mat,v);
}