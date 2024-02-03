#include <stdio.h>
#include <stdlib.h>

typedef struct Honeypot
{
    int HoneypotID;
    double ip;
    struct Honeypot *left;
    struct Honeypot *right;
} Honeypot;

Honeypot *createHoneypot(int HoneypotID, double ip)
{
    Honeypot *newHoneypot = (Honeypot *)malloc(sizeof(Honeypot));
    newHoneypot->HoneypotID = HoneypotID;
    newHoneypot->ip = ip;
    newHoneypot->left = NULL;
    newHoneypot->right = NULL;
    return newHoneypot;
}

Honeypot *insertHoneypot(Honeypot *root, int HoneypotID, double ip)
{
    if (root == NULL)
    {
        return createHoneypot(HoneypotID, ip);
    }

    if (HoneypotID < root->HoneypotID)
    {
        root->left = insertHoneypot(root->left, HoneypotID, ip);
    }
    else if (HoneypotID > root->HoneypotID)
    {
        root->right = insertHoneypot(root->right, HoneypotID, ip);
    }

    return root;
}

void inOrderTraversal(Honeypot *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("Honeypot ID: %d, ip: %.2lf\n", root->HoneypotID, root->ip);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Honeypot *root)
{
    if (root != NULL)
    {
        printf("Honeypot ID: %d, ip: %.2lf\n", root->HoneypotID, root->ip);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Honeypot *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("Honeypot ID: %d, ip: %.2lf\n", root->HoneypotID, root->ip);
    }
}

int main()
{
    Honeypot *rootLevelOrder = NULL;
    Honeypot *rootDepthOrder = NULL;

    int levelOrderIDs[] = {1, 2, 3, 4, 5, 6, 7};
    double levelOrderIp[] = {192.1, 0.1, 168.0, 72.0, 81.0, 87.0, 167.0};

    for (int i = 0; i < sizeof(levelOrderIDs) / sizeof(levelOrderIDs[0]); i++)
    {
        rootLevelOrder = insertHoneypot(rootLevelOrder, levelOrderIDs[i], levelOrderIp[i]);
    }

    int depthOrderIDs[] = {4, 2, 1, 3, 6, 5, 7};
    double depthOrderIp[] = {192.1, 0.1, 168.0, 72.0, 81.0, 87.0, 167.0};

    for (int i = 0; i < sizeof(depthOrderIDs) / sizeof(depthOrderIDs[0]); i++)
    {
        rootDepthOrder = insertHoneypot(rootDepthOrder, depthOrderIDs[i], depthOrderIp[i]);
    }

    printf("In-Order Traversal (Level Order):\n");
    inOrderTraversal(rootLevelOrder);

    printf("\nPre-Order Traversal (Level Order):\n");
    preOrderTraversal(rootLevelOrder);

    printf("\nPost-Order Traversal (Level Order):\n");
    postOrderTraversal(rootLevelOrder);

    printf("\nIn-Order Traversal (Depth Order):\n");
    inOrderTraversal(rootDepthOrder);

    printf("\nPre-Order Traversal (Depth Order):\n");
    preOrderTraversal(rootDepthOrder);

    printf("\nPost-Order Traversal (Depth Order):\n");
    postOrderTraversal(rootDepthOrder);

    return 0;
}