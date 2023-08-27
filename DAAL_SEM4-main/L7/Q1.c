#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
typedef struct node
{
    nodeptr lchild;
    nodeptr rchild;
    int data;
}node;

nodeptr getnode()
{
    nodeptr root = (nodeptr)malloc(sizeof(node));
    return root;
}

nodeptr create_BST(nodeptr root,int x)
{
    if(root == NULL)
    {
        root = getnode();
        root->data = x;
        return root;
    }
    else if(x < root->data)
        root->lchild = create_BST(root->lchild,x);
    else if(x > root->data)
        root->rchild = create_BST(root->rchild,x);
    return root;

}
int max(int a,int b)
{
    if(a >= b)
        return a;
    else
        return b;
}
int height(nodeptr root)
{
    if(root == NULL)
        return 0;
    return(1+max(height(root->lchild),height(root->rchild)));
}

int balance_factor(nodeptr root)
{
    printf("\nlheight:%d,rheight:%d",height(root->lchild),height(root->rchild));
    int bf = height(root->lchild) - height(root->rchild);
    return bf;
}

void postorder(nodeptr root)
{
    if(root)
    {
        printf("\nbf of %d :%d",root->data,balance_factor(root));
        postorder(root->lchild);
        postorder(root->rchild);
    }
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
    printf("enter the root node:");
    scanf("%d",&x);
    root = create_BST(root,x);

    while(x != -1)
    {
        printf("\nenter the BST node(-1 to stop):");
        scanf("%d",&x);
        if(x == -1)
            break;
        root = create_BST(root,x);
        
    }
    preorder(root);
    postorder(root);
}

//     5
//  3      7
//    4  6   9
//preorder(VLR):5 3 4 7 6 9

