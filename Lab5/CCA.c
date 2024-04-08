#include <stdio.h>
#include <stdlib.h>

// Define a binary tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Create a new node with a given key
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find the Closest Common Ancestor (CCA) of two nodes in a Binary Tree
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    // If either n1 or n2 matches the key at the current node, then this node is the CCA
    if (root->key == n1 || root->key == n2) {
        return root;
    }

    // Recursively search for the CCA in the left and right subtrees
    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    // If both left and right subtrees return non-null values, then the current node is the CCA
    if (leftCCA != NULL && rightCCA != NULL) {
        return root;
    }

    // If one of the subtrees is non-null, return the non-null value
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

// Function to build a binary tree based on user input
struct Node* buildTree() {
    int key;
    struct Node* root = NULL;

    printf("Enter the root value of the binary tree: ");
    scanf("%d", &key);
    root = newNode(key);

    printf("Enter the left child value of the root (or -1 if no left child): ");
    scanf("%d", &key);
    if (key != -1) {
        root->left = buildTree();
    }

    printf("Enter the right child value of the root (or -1 if no right child): ");
    scanf("%d", &key);
    if (key != -1) {
        root->right = buildTree();
    }

    return root;
}

int main() {
    struct Node* root = buildTree();

    int n1, n2;
    printf("Enter the values of nodes n1 and n2: ");
    scanf("%d %d", &n1, &n2);

    struct Node* cca = findCCA(root, n1, n2);

    if (cca != NULL) {
        printf("Closest Common Ancestor of %d and %d is %d\n", n1, n2, cca->key);
    } else {
        printf("Closest Common Ancestor not found\n");
    }

    return 0;
}
