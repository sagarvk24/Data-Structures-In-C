#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
} b;

b *insertion(b *root, int val)
{
    if (root == NULL)
    {
        root = (b *)malloc(sizeof(b));

        if (root == NULL)
        {
            printf("Memory Overflow!!");
            return NULL;
        }
        root->data = val;
        root->left = root->right = NULL;
    }
    else
    {
        if (val <= root->data)
            root->left = insertion(root->left, val);
        else
            root->right = insertion(root->right, val);
    }

    return root;
}

b *maxnode(b *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        if (root->right == NULL)
            return root;
        else
            return maxnode(root->right);
    }
}

b *deletion(b *root, int val)
{
    b *temp=NULL;
    if(root==NULL)
        printf("\nElement Not Found!");
 
    else if(val<root->data)
        root->left=deletion(root->left,val);
    else if(val>root->data)
        root->right=deletion(root->right,val);
    else
    {
        //found element
        if(root->left && root->right)
        {
            /*replace with largest in left subtree*/
            temp=maxnode(root->left);
            root->data=temp->data;
            root->left=deletion(root->left,root->data);
        }
        else if(root->left==NULL && root->right==NULL)
        {
            return NULL;
        }
        else
        {
            /*one child*/
            temp=root;
            if(root->left==NULL)
                root=root->right;
            if(root->right==NULL)
                root=root->left;
            free(temp);
        }
    }
    return root;
}

b *Search(b *root,int data)
{
    b *p=root;
    while(p->data!=data)
    {
        if(p!=NULL)
        {
            printf(" %d",p->data);
            if(p->data>data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }

            if(p==NULL)
            {
                return NULL;
            }
        }
    }
    return p;
}

void inorder(b *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void preorder(b *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(b *root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        inorder(root->left);
        inorder(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    int choice, val, target;
    b *root = NULL;
    do{
        printf("\nEnter Your Choice ::::\n");
        printf("\n1. Insertion\n2. Deletion\n3. Display Preorder\n4. Display Inorder\n5. Display Postorder\n6. Maximum Node\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the value of node :");
                scanf("%d", &val);
                root = insertion(root, val);
                break;
            }
            case 2:
            {
                printf("Enter the node you want to delete : ");
                scanf("%d", &val);
                root = deletion(root, val);
                break;
            }
            case 3:
            {
                printf("Preorder Traversal ::\n");
                preorder(root);
                break;
            }
            case 4:
            {
                printf("Inorder Traversal ::\n");
                inorder(root);
                break;
            }
            case 5:
            {
                printf("Postorder Traversal ::\n");
                postorder(root);
                break;
            }
            case 6:
            {
                printf("Maximum Node : %d", *maxnode(root));
                break;
            }
            default:
            {
                printf("Wrong Choice!!");
                exit(0);
            }
        }
    }while(1);
    return 0;
}
