#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int info;
    struct tree *llink;
    struct tree *rlink;
};

    struct tree *getnode(int value)
    {
        struct tree *root;
        root=(struct tree *)malloc(sizeof(struct tree ));
        root->info=value;
        root->rlink=root->llink=NULL;
        return root;
    }

    struct tree * insert(struct tree *root , int value)
    {
        if(root==NULL)
        {
            return getnode(value);
        }
        if(value<root->info)
        root->llink=insert(root->llink,value);

        if(value>root->info)
        root->rlink=insert(root->rlink,value);
        return root;
    }

void inorder(struct tree *root)
{
    if(root!=NULL)
    {
    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
    }
}
void preorder(struct tree *root)
{
    if(root!=NULL)
    {
    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
    
    }
}

void postorder(struct tree *root)
{
    if(root!=NULL)
    {
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->info);
    }
}

 struct tree *search(struct tree *root,int value)
 {
    if(root==NULL)
        printf("\n No Values \n");
    
    else if(value<root->info)
    root->llink=search(root->llink,value);

    else if(value>root->info)
    root->rlink=search(root->rlink,value);

    else
    printf("\n element is %d",root->info);
 }

 int main()
 {
    struct tree *root =NULL;
    int n,ch,value;
    for(;;)
    {
        printf("\n 1.insert\n 2.inorder \n3.preorder \n 4.postorder \n 5.search \n 6.exit \n");
        printf("\n Enter the choice -->");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:printf("\n enter the number of values \n");
        scanf("%d",&n);
        printf("Enter the BST Values \n");
        for(int i=0;i<n;i++)
        {
            scanf("%d",&value);
            root=insert(root,value);
        }
        break;

        case 2: printf("\n Inorder traversal \n");
        inorder(root);
        break;
        
        case 3: printf("\n preorder traversal \n");
        preorder(root);
        break;

        case 4: printf("\n postorder traversal \n");
        postorder(root);
        break;

        case 5:printf("\n Enter element to search \n");
        scanf("%d",&value);
        root=search(root,value);
        break;

        default:printf("Invalid");
            break;
        }
    }
 }