#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *current, *parent;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;

                if (current == NULL)
                {
                    parent->left = temp;
                    return;
                }
            }
            else
            {
                current = current->right;
                if (current == NULL)
                {
                    current->right = temp;
                    return;
                }
            }
        }
    }
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

    // int count;
    int a[6] = {12, 10, 32, 21, 24, 8};
    // printf("How many elements in the tree: ");
    // scanf("%d", &count);
    // printf("Enter elements: ");
    // for (int i = 0; i < count; i++)
    // {
    //     scanf("%d", &a[i]);
    // }
    for (int i = 0; i < 6; i++)
    {
        insert(a[i]);
    }

    // printf("Indorder:");
    // InorderDisplay(root);
    // printf("Preorder:");
    // preorderDisplay(root);
    // printf("Postorder:");
    // postorderDisplay(root);
    return 0;
}
