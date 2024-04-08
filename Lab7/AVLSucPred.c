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


// Function to find the node with minimum key value in a subtree rooted with node
struct AVLNode* minValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Function to find the node with maximum key value in a subtree rooted with node
struct AVLNode* maxValueNode(struct AVLNode* node) {
    struct AVLNode* current = node;

    // Loop down to find the rightmost leaf
    while (current->right != NULL)
        current = current->right;

    return current;
}

// Function to find successor of a given node in the tree
struct AVLNode* successor(struct AVLNode* root, int key) {
    // Search for the node
    struct AVLNode* current = root;
    struct AVLNode* successor = NULL;

    while (current != NULL) {
        if (current->data > key) {
            successor = current;
            current = current->left;
        } else if (current->data < key) {
            current = current->right;
        } else {
            if (current->right != NULL)
                return minValueNode(current->right);
            break;
        }
    }

    return successor;
}

// Function to find predecessor of a given node in the tree
struct AVLNode* predecessor(struct AVLNode* root, int key) {
    // Search for the node
    struct AVLNode* current = root;
    struct AVLNode* predecessor = NULL;

    while (current != NULL) {
        if (current->data < key) {
            predecessor = current;
            current = current->right;
        } else if (current->data > key) {
            current = current->left;
        } else {
            if (current->left != NULL)
                return maxValueNode(current->left);
            break;
        }
    }

    return predecessor;
}

int main() {
    struct Node* root = NULL; // Assuming the AVL tree has been constructed elsewhere

    // Example: Assume the AVL tree has been constructed with some keys

    int key_to_find;
    printf("Enter the key to find its successor and predecessor: ");
    scanf("%d", &key_to_find);

    struct AVLNode* succ = successor(root, key_to_find);
    struct AVLNode* pred = predecessor(root, key_to_find);

    if (succ != NULL)
        printf("Successor of %d is %d\n", key_to_find, succ->data);
    else
        printf("No successor for %d\n", key_to_find);

    if (pred != NULL)
        printf("Predecessor of %d is %d\n", key_to_find, pred->data);
    else
        printf("No predecessor for %d\n", key_to_find);

    return 0;
}

