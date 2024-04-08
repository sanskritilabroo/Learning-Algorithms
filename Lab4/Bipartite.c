// . Write a program to check whether a graph is bipartite or not using
// i. DFS to check for bipartite
// ii. BFS to check for bipartite
//  A graph is said to be bipartite if all its vertices can be partitioned into two 
//  disjoint subsets X and Y so that every edge connects a vertex in X with a vertex 
//  in Y.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

typedef struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
bool isBipartiteDFS(Graph* graph);
bool isBipartiteBFS(Graph* graph);

Queue* createQueue(unsigned capacity);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Graph is %s bipartite (DFS).\n", isBipartiteDFS(graph) ? "" : "not");
    printf("Graph is %s bipartite (BFS).\n", isBipartiteBFS(graph) ? "" : "");

    return 0;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjList = (Node**)calloc(vertices, sizeof(Node*));
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

bool isBipartiteDFSUtil(Graph* graph, int vertex, int color[]) {
    if (color[vertex] == -1) {
        color[vertex] = 1;

        Node* temp = graph->adjList[vertex];
        while (temp != NULL) {
            if (!isBipartiteDFSUtil(graph, temp->vertex, color))
                return false;
            temp = temp->next;
        }
        return true;
    } else {
        return color[vertex] == 1;
    }
}

bool isBipartiteDFS(Graph* graph) {
    int* color = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        if (color[i] == -1 && !isBipartiteDFSUtil(graph, i, color)) {
            free(color);
            return false;
        }
    }

    free(color);
    return true;
}

bool isBipartiteBFS(Graph* graph) {
    int* color = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        if (color[i] == -1) {
            Queue* queue = createQueue(MAX_VERTICES);
            enqueue(queue, i);
            color[i] = 0;

            while (!isQueueEmpty(queue)) {
                int currentVertex = dequeue(queue);

                Node* temp = graph->adjList[currentVertex];
                while (temp != NULL) {
                    if (color[temp->vertex] == -1) {
                        color[temp->vertex] = 1 - color[currentVertex];
                        enqueue(queue, temp->vertex);
                    } else if (color[temp->vertex] == color[currentVertex]) {
                        free(color);
                        return false;
                    }
                    temp = temp->next;
                }
            }
        }
    }

    free(color);
    return true;
}

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(capacity * sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

bool isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}
