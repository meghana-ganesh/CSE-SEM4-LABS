#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;

typedef struct node
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
}node;
nodeptr getnode()
{
    nodeptr temp = (nodeptr)malloc(sizeof(node));
    return temp;
}

nodeptr createbintree(int item,int *count)
{
    int x;
    nodeptr temp;
    if(item != -1)
    {
        temp = getnode();
        temp->data = item;
        (*count)++;
        printf("\nenter the lchild of the node %d:",item);
        scanf("%d",&x);
        temp->lchild = createbintree(x,count);

        printf("\nenter the rchild of the node %d:",item);
        scanf("%d",&x);
        temp->rchild = createbintree(x,count);
        return temp;
    }
    return NULL;
}
void preorder(nodeptr root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);

    }
}

int main()
{
    nodeptr root = NULL;
    int x;
    int count = 0;
    printf("enter the rootnode of the tree:");
    scanf("%d",&x);
    root = createbintree(x,&count);
    preorder(root);
    printf("\ncount:%d",count);
    return 0;
}
//     5
//  7     8
// 3     4 2

//preorder(VLR):5 7 3 8 4 2


