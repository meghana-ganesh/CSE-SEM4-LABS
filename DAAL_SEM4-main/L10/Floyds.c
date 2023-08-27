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

int min(int a,int b)
{
    if(a >= b)
        return b;
    else
        return a;
}
void Floyds(int **mat,int v)
{
    for(int k=0;k<v;k++)
    {
        for(int j=0;j<v;j++)
        {
            for(int i=0;i<v;i++)
            {
                mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
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
            printf("distance between %d and %d(1000 for infinity)?",i+1,j+1);
            scanf("%d",&ans);
            mat[i][j] = ans;
        }
    }
    display(mat,v);
    printf("after applying floyds algorithm:\n");
    Floyds(mat,v);
    display(mat,v);
}