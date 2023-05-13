#include <stdio.h>
#include <stdlib.h>

typedef struct BT
{
    int data;
    struct BT *left;
    struct BT *right;
} b;

b *create(){
    int val;
    printf("Value of Node :");
    scanf("%d", &val);
    if (val == -1)
        return 0;
    else
    {
        b *p = (b *)malloc(sizeof(b));
        p->data = val;
        printf("\n");
        printf("Enter the value of Left Node of %d :\n", val);
        p->left = create();
        printf("\n");
        printf("Enter the value of Right Node of %d:\n", val);
        p->right = create();
        return p;
    }
}

void preorder(b *root){
    if (root){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(b *root){
    if (root){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(b *root){
    if (root){
        preorder(root->left);
        preorder(root->right);
        printf("%d\t", root->data);
    }
}

int main(){
    b *root = NULL;
    root = create();
    int choice;
    do{
        printf("\nEnter the type of Traversal you want :: \n\n1. Preorder\n2. Inorder\n3. Postorder\t");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:{
            preorder(root);
            break;
        }
        case 2:{
            inorder(root);
            break;
        }
        case 3:{
            postorder(root);
            break;
        }
        default:{
            printf("Wrong Choice!!");
            exit(0);
        }
        }
    } while (1);
    return 0;
}