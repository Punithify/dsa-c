#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

struct node *insert(int arr[], struct node *root, int i, int n)
{

    if (i < n)
    {
        struct node *temp = newNode(arr[i]);
        root = temp;
        root->left = insert(arr, root->left, 2 * i + 1, n);
        root->right = insert(arr, root->right, 2 * i + 2, n);
    }
    return root;
}
void InorderDisplay(struct node *root)
{
    if (root != NULL) // inorder
    {
        InorderDisplay(root->left);
        printf("%d\t ", root->data);
        InorderDisplay(root->right);
    }
}
int main()
{
    int count;
    int a[100];
    printf("How many elements in the tree: ");
    scanf("%d", &count);
    printf("Enter elements: ");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &a[i]);
    }
    struct node *root = insert(a, root, 0, count);
    InorderDisplay(root);
    return 0;
}