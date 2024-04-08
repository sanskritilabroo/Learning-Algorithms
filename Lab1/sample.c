// Write an algorithm and program to implement a doubly linked list which supports 
//  the following operations 
// i. Create the list by adding each node at the front. 
// ii. Insert a new node to the left of the node whose key value is read as an input. 
// iii. Delete all occurrences of a given key, if it is found. Otherwise, display 
// appropriate message. 
// iv. Search a node based on its key value. 
// v. Display the contents of the list

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    int val;
    struct node *llink, *rlink;
};

typedef struct node *NODE;
NODE head = NULL;

// Function to create a list with a given value
void CreateList(int val) {
    NODE node;
    if (head == NULL) {
        // Allocate memory for a new node
        node = (NODE)malloc(sizeof(struct node));
        node->llink = node->rlink = NULL;
        node->val = val;
        head = node;
    } else {
        printf("List is already created.\n");
    }
}

// Function to insert a new node with a given value before a specified node value
void insertIntoList(int before, int val) {
    NODE node, nn;
    node = head;
    while (node != NULL && node->val != before)
        node = node->rlink;

    if (node != NULL) {
        // Allocate memory for a new node
        nn = (NODE)malloc(sizeof(struct node));
        nn->llink = nn->rlink = NULL;
        nn->val = val;

        if (node->llink != NULL) {
            node->llink->rlink = nn;
            nn->llink = node->llink;
            nn->rlink = node;
            node->llink = nn;
        } else {
            nn->rlink = node;
            node->llink = nn;
            head = nn;
        }
    } else {
        printf("Unable to insert, node with value %d not found.\n", val);
    }
}

// Function to delete all nodes with a given value
void deleteAll(int delVal) {
    NODE node, nxtNode;
    node = head;
    
    while (node != NULL) {
        if (node->val == delVal) {
            if (node->llink != NULL) {
                node->llink->rlink = node->rlink;
                if (node->rlink != NULL) {
                    node->rlink->llink = node->llink;
                    nxtNode = node->rlink;
                    free(node);
                    node = nxtNode;
                } else {
                    node->llink->rlink = NULL;
                    free(node);
                    node = NULL;
                }
            } else {
                if (node->rlink != NULL) {
                    node->rlink->llink = NULL;
                    head = node->rlink;
                    free(node);
                    node = head;
                } else {
                    free(node);
                    head = node = NULL;
                }
            }
        } else {
            node = node->rlink;
        }
    }
}

// Function to search for a node with a given value
void searchNode(int searchVal) {
    NODE node;
    node = head;
    while (node != NULL) {
        if (node->val == searchVal) {
            printf("Node is found with key %d.\n", searchVal);
            return;
        }
        node = node->rlink;
    }
    printf("Node with key %d not found.\n", searchVal);
}

// Function to display all nodes in the list
void displayAll() {
    NODE node;
    node = head;
    while (node != NULL) {
        printf("Node with value %d\n", node->val);
        node = node->rlink;
    }
}

int main() {
    int choice, val, before;
    do {
        printf("1. Create List\n");
        printf("2. Insert into List\n");
        printf("3. Delete all by value\n");
        printf("4. Search by value\n");
        printf("5. Display all\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Please enter the node value: ");
                scanf("%d", &val);
                CreateList(val);
                break;

            case 2:
                printf("Please enter the node value to insert: ");
                scanf("%d", &val);
                printf("Please enter the node value before which new node has to be inserted: ");
                scanf("%d", &before);
                insertIntoList(before, val);
                break;

            case 3:
                printf("Enter the node value to be deleted: ");
                scanf("%d", &val);
                deleteAll(val);
                break;

            case 4:
                printf("Enter the node value to be searched: ");
                scanf("%d", &val);
                searchNode(val);
                break;

            case 5:
                displayAll();
                break;

            case 6:
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
