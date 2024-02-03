#include <stdio.h>
#include <stdlib.h>

struct node
{
    int port;

    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int port)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->port = port;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            if (port < parent->port)
            {
                current = current->leftChild;

                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            else
            {
                current = current->rightChild;

                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

struct node *search(int port)
{
    struct node *current = root;

    while (current != NULL)
    {
        if (port == current->port)
        {
            return current; // Node found
        }
        else if (port < current->port)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }

    return NULL; // Node not found
}

struct node *findMin(struct node *root)
{
    while (root->leftChild != NULL)
    {
        root = root->leftChild;
    }
    return root;
}

struct node *deleteNode(struct node *root, int port)
{
    if (root == NULL)
    {
        return root;
    }

    if (port < root->port)
    {
        root->leftChild = deleteNode(root->leftChild, port);
    }
    else if (port > root->port)
    {
        root->rightChild = deleteNode(root->rightChild, port);
    }
    else
    {
        // Node with only one child or no child
        if (root->leftChild == NULL)
        {
            struct node *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            struct node *temp = root->leftChild;
            free(root);
            return temp;
        }

        // Node with two children
        struct node *temp = findMin(root->rightChild);
        root->port = temp->port;
        root->rightChild = deleteNode(root->rightChild, temp->port);
    }

    return root;
}

int calculateHeight(struct node *root)
{
    if (root == NULL)
    {
        return -1; // Height of an empty tree is -1
    }

    int leftHeight = calculateHeight(root->leftChild);
    int rightHeight = calculateHeight(root->rightChild);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void inOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->leftChild);
        printf("%d ", root->port);
        inOrderTraversal(root->rightChild);
    }
}

void preOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->port);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->port);
    }
}

int main()
{
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};

    for (i = 0; i < 7; i++)
        insert(array[i]);

    printf("\nIn-order traversal: ");
    inOrderTraversal(root);

    printf("\nPre-order traversal: ");
    preOrderTraversal(root);

    printf("\nPost-order traversal: ");
    postOrderTraversal(root);

    int searchport;
    printf("\nEnter a value to search in the BST: ");
    scanf("%d", &searchport);
    struct node *searchResult = search(searchport);
    if (searchResult != NULL)
    {
        printf("Node with value %d found in the BST.\n", searchport);
    }
    else
    {
        printf("Node with value %d not found in the BST.\n", searchport);
    }

    int deleteport;
    printf("\nEnter a value to delete from the BST: ");
    scanf("%d", &deleteport);
    root = deleteNode(root, deleteport);
    printf("BST after deleting %d: ", deleteport);
    inOrderTraversal(root);

    int height = calculateHeight(root);
    printf("\nHeight of the BST: %d\n", height + 1);

    return 0;
}