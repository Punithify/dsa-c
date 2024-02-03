#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    int left, right;
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    printf("Enter the Left node value for %d (-1 if empty)", data);
    scanf("%d", &left);
    if (left == -1)
    {
        node->left == NULL;
    }
    else
    {
        node->left = newNode(left);
    }
    printf("Enter the Right node value for %d (-1 if empty)\n", data);
    scanf("%d", &right);
    if (right == -1)
    {
        node->right = NULL;
    }
    else
    {
        node->right = newNode(right);
    }
    return (node);
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
    int data;
    struct node *root = NULL;
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    if (root == NULL)
    {
        printf("Enter the data for the root node");
        scanf("%d", &data);
        root = newNode(data);
        printf("\n Inorder:");
        InorderDisplay(root);
        printf("\n Preorder:");
        preorderDisplay(root);
        printf("\n Postorder:");
        postorderDisplay(root);
    }
}
