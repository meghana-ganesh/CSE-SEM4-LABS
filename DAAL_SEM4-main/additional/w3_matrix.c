#include<stdio.h>
#include<stdlib.h>


int** allocate(int r,int c)
{
    int **mat = (int**)malloc(r*sizeof(int*));
    for(int i=0;i<r;i++)
    {
        mat[i] = (int*)malloc(c*sizeof(int));
    }
    return mat;
}

void input(int **mat,int r,int c)
{
    printf("\nenter the elements:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    
}

void display(int **mat,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void multiply(int **mat1,int **mat2,int r1,int c1,int r2,int c2,int** res)
{
    
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            res[i][j] = 0;
            for(int k=0;k<c1;k++)
            {

                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main()
{
    int r1,c1,r2,c2;
    printf("enter the row & col of mat1:");
    scanf("%d %d",&r1,&c1);

    printf("\nenter the row & col of mat2:");
    scanf("%d %d",&r2,&c2);

    if(c1 != r2)
        printf("Matrix multiplication not possible");
    
    
    int **mat1 = allocate(r1,c1);
    input(mat1,r1,c1);
    display(mat1,r1,c1);

    
    int **mat2 = allocate(r2,c2);
    input(mat2,r2,c2);
    display(mat2,r2,c2);

    
    int **res = allocate(r1,c2);
    multiply(mat1,mat2,r1,c1,r2,c2,res);
    display(res,r1,c2);
}