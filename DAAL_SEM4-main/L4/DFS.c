#include<stdio.h>
#include<stdlib.h>


void createadjmat(int **mat,int v)
{
    int c;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            // printf("\ndoes vertex %d have an edge with %d(1/0)?",i+1,j+1);
            // fflush(stdin);
            scanf("%d",&mat[i][j]);
            // if(c == 1)
            //     mat[i][j] = 1;
            // else if(c == 0)
            //     mat[i][j] = 0;
            // else
            // {
            //     printf("invalid character entered!!");
            //     return;
            // }
        }
    }
}

void dfs_traversal(int **mat,int v,int start)
{
    int tos = -1,i = start-1,k = 0,empty = 1,l=0,j;
    int *stack = (int*)malloc(v*sizeof(int));
    int visited[v+1],visit_order[v],pop_order[v]; // increased size of visited v to v+1
    
    stack[++tos] = start;
    visited[start] = 1;
    visit_order[k++] = start;


    for(int i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            empty = 1;
            if(mat[i][j] == 1 && visited[j+1] != 1)
            {
                
                empty = 0;
                stack[++tos] = j+1;
                visited[j+1] = 1;
                visit_order[k++] = j+1;
                i = j;
                j = 0;
            }
            
        }
        if(empty == 1)
        {
            if(tos != -1)
            {
                pop_order[l++] = stack[tos--];
                int x = stack[tos];
                i = x-2;  /* changed this from x-1 to x-2 because once you make it x-1 
                it will go back to the loop and increment the value making it x but you wanted 
                i to start from x-1 so if you do x-2 it will go to the for loop and increment i making it x-1*/
                j = 0;
            }
        }
        
    }

    

    printf("\nvisit order:\n");
    for(int j=0;j<k;j++)
    {
        printf("%d ",visit_order[j]);
    }
    printf("\npop order:\n");

    for(int j=0;j<l;j++)
    {
        printf("%d ",pop_order[j]);
    }
}

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

int main()
{
    int v,e;
    printf("enter the no. of vertices:");
    scanf("%d",&v);
    
    int **mat = (int**)malloc(v*sizeof(int*));
    
    for(int i=0;i<v;i++)
    {
        mat[i] = (int*)malloc(v*sizeof(int));
    }
    createadjmat(mat,v);
    // display(mat,v);
    dfs_traversal(mat,v,1);
}