#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return new_node(x);
    else if (data > root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

void InorderDisplay(struct node *root)
{
    if (root != NULL) // inorder
    {
        InorderDisplay(root->left);
        printf("%d\t", root->data);
        InorderDisplay(root->right);
    }
}

void preorderDisplay(struct node *root)
{
    if (root != NULL) // preorder
    {
        printf("%d\t", root->data);
        preorderDisplay(root->left);
        preorderDisplay(root->right);
    }
}

void postorderDisplay(struct node *root)
{
    if (root != NULL) // postorder
    {
        postorderDisplay(root->left);
        postorderDisplay(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{

    struct node *root;
    root = new_node(20);
    insert(root, 5);
    return 0;
}
