#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int vertex) {
    if (queue->rear == MAX_VERTICES - 1)
        printf("Queue is full\n");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = vertex;
    }
}

int dequeue(struct Queue* queue) {
    int element;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        element = queue->items[queue->front];
        if (queue->front >= queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        return element;
    }
}

void initGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* graph, int source, int destination) {
    graph->adjacencyMatrix[source][destination] = 1;
}

void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    int opcount = 0;
    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        for (int i = 0; i < graph->numVertices; i++) 
        {
            opcount++;
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("opcount : %d",opcount);
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    initGraph(graph, 6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);

    printf("BFS Traversal: \n");
    BFS(graph, 0);
}
