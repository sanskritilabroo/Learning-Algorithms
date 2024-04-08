//Write a program to implement Stack and Queue using circular doubly linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Circular Doubly Linked List
typedef struct {
    Node* front;
    Node* rear;
} CircularDoublyLinkedList;

// Function to initialize a circular doubly linked list
void initializeCDLL(CircularDoublyLinkedList* list) {
    list->front = list->rear = NULL;
}

// Function to check if the circular doubly linked list is empty
int isEmpty(CircularDoublyLinkedList* list) {
    return list->front == NULL;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = newNode->prev = NULL;
    }
    return newNode;
}

// Function to insert an element at the front of the circular doubly linked list (push operation for stack)
void insertAtFront(CircularDoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(list)) {
        list->front = list->rear = newNode;
        newNode->next = newNode->prev = newNode; // Circular link
    } else {
        newNode->next = list->front;
        newNode->prev = list->rear;
        list->front->prev = newNode;
        list->rear->next = newNode;
        list->front = newNode;
    }
}

// Function to insert an element at the rear of the circular doubly linked list (enqueue operation for queue)
void insertAtRear(CircularDoublyLinkedList* list, int value) {
    Node* newNode = createNode(value);
    if (isEmpty(list)) {
        list->front = list->rear = newNode;
        newNode->next = newNode->prev = newNode; // Circular link
    } else {
        newNode->next = list->front;
        newNode->prev = list->rear;
        list->front->prev = newNode;
        list->rear->next = newNode;
        list->rear = newNode;
    }
}

// Function to delete an element from the front of the circular doubly linked list (pop operation for stack)
void deleteFromFront(CircularDoublyLinkedList* list) {
    if (!isEmpty(list)) {
        Node* temp = list->front;
        if (list->front == list->rear) {
            list->front = list->rear = NULL;
        } else {
            list->front = temp->next;
            list->front->prev = list->rear;
            list->rear->next = list->front;
        }
        free(temp);
    }
}

// Function to delete an element from the rear of the circular doubly linked list (dequeue operation for queue)
void deleteFromRear(CircularDoublyLinkedList* list) {
    if (!isEmpty(list)) {
        Node* temp = list->rear;
        if (list->front == list->rear) {
            list->front = list->rear = NULL;
        } else {
            list->rear = temp->prev;
            list->rear->next = list->front;
            list->front->prev = list->rear;
        }
        free(temp);
    }
}

// Function to display the elements of the circular doubly linked list
void display(CircularDoublyLinkedList* list) {
    if (!isEmpty(list)) {
        Node* current = list->front;
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != list->front);
        printf("\n");
    } else {
        printf("List is empty.\n");
    }
}

int main() {
    CircularDoublyLinkedList stack, queue;
    initializeCDLL(&stack);
    initializeCDLL(&queue);

    // Push elements onto the stack
    insertAtFront(&stack, 10);
    insertAtFront(&stack, 20);
    insertAtFront(&stack, 30);

    printf("Stack after push operations: ");
    display(&stack);

    // Pop an element from the stack
    deleteFromFront(&stack);
    printf("Stack after pop operation: ");
    display(&stack);

    // Enqueue elements into the queue
    insertAtRear(&queue, 40);
    insertAtRear(&queue, 50);
    insertAtRear(&queue, 60);

    printf("Queue after enqueue operations: ");
    display(&queue);

    // Dequeue an element from the queue
    deleteFromFront(&queue);
    printf("Queue after dequeue operation: ");
    display(&queue);

    return 0;
}
