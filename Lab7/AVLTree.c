//Write a program to create the AVL tree by iterative insertion
#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

// Structure for a node in the AVL tree
struct AVLNode 
{
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

// Function to create a new node
struct AVLNode *newNode(int key) {
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get the height of a node
int height(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}


// Function to perform right rotation
struct AVLNode *rightRotate(struct AVLNode *root) {
    struct AVLNode *temp = root->left;
    struct AVLNode *temp2 = temp->right;
 //         root       --->      temp
//         /  \                 /   \          //
//     temp    y               x   root
//     /   \                       /  \        //
//    x   temp2                temp2   y

    // Perform rotation
    temp->right = root;
    root->left = temp2;

    // Update heights
    root->height = max(height(root->left), height(root->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;

    // Return new root
    return temp;
}

// Function to perform left rotation
struct AVLNode *leftRotate(struct AVLNode *temp) {
    struct AVLNode *root = temp->right;
    struct AVLNode *temp2 = root->left;
 //        root       --->      temp
//        /  \                 /   \         //
//       y  temp             root   x
//          /  \             /  \            //
//      temp2   x           y   temp2
    // Perform rotation
    root->left = temp;
    temp->right = temp2;

    // Update heights
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    root->height = max(height(root->left), height(root->right)) + 1;

    // Return new root
    return root;
}

// Get Balance factor of node
int getBalance(struct AVLNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Function to insert a node into AVL tree
struct AVLNode *insertNode(struct AVLNode *node, int key) {
    // Perform the normal BST insertion
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insertNode(node->left, key);
    else if (key > node->data)
        node->right = insertNode(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are four cases

    // Left Left Case
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Function to print preorder traversal of AVL tree
void preOrder(struct AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct AVLNode *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    printf("Preorder traversal of AVL tree: ");
    preOrder(root);

    return 0;
}