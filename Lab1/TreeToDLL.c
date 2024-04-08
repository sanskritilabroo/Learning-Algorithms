#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct DoublyListNode {
    int data;
    struct DoublyListNode* prev;
    struct DoublyListNode* next;
} DoublyListNode;

TreeNode* createTreeNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}




/**
 * Converts a binary tree to a doubly linked list using in-order traversal.
 *
 * param root The root of the binary tree.
 * param tail A pointer to the tail of the doubly linked list.
 * return The head of the doubly linked list.
 */
DoublyListNode* binaryTreeToDoublyList(TreeNode* root, DoublyListNode** tail) {
    // Base case: If the current root is NULL, return NULL.
    if (root == NULL) {
        return NULL;
    }

    // Recursively convert the left subtree and get the leftList.
    DoublyListNode* leftList = binaryTreeToDoublyList(root->left, tail);

    // Create a new DoublyListNode for the current root.
    DoublyListNode* listNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
    listNode->data = root->data;
    listNode->prev = *tail;
    listNode->next = NULL;

    // Update the tail pointer based on the current node.
    if (*tail == NULL) {
        // If tail is NULL, this is the first node, so set it as the tail.
        *tail = listNode;
    } else {
        // Otherwise, link the current node to the previous tail and update tail.
        (*tail)->next = listNode;
        *tail = listNode;
    }

    // Recursively convert the right subtree and get the rightList.
    DoublyListNode* rightList = binaryTreeToDoublyList(root->right, tail);

    // If the leftList is NULL, return the current node as the head of the list.
    if (leftList == NULL) {
        return listNode;
    } else {
        // Otherwise, return the leftList (head of the list).
        return leftList;
    }
}




void printDoublyList(DoublyListNode* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    TreeNode* root = NULL;

    // Example binary tree creation (you can modify this part)
    root = createTreeNode(4);
    root->left = createTreeNode(2);
    root->right = createTreeNode(6);
    root->left->left = createTreeNode(1);
    root->left->right = createTreeNode(3);
    root->right->left = createTreeNode(5);
    root->right->right = createTreeNode(7);

    DoublyListNode* tail = NULL;
    DoublyListNode* doublyList = binaryTreeToDoublyList(root, &tail);

    printf("Doubly Linked List: ");
    printDoublyList(doublyList);

    return 0;
}
