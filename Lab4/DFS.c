// The time complexity of DFS in a graph or tree is generally expressed as O(V + E),
//  where V is the number of vertices (nodes) and E is the number of edges.

// In an adjacency list representation of a graph:

// Each vertex is visited once.
// Each edge is traversed exactly once.
// In an adjacency matrix representation:

// Checking for neighbors takes O(V) time.
// For each vertex, visiting all neighbors results in O(V^2) time in total.
// In the worst case, where the graph is a dense graph (many edges), the time complexity of DFS can be considered O(V^2).

// Breadth-First Search (BFS):
// BFS explores nodes level by level, visiting all neighbors at the current depth before moving on to the next depth level. The time complexity of BFS in a graph or tree is also expressed as O(V + E), where V is the number of vertices (nodes) and E is the number of edges.

// In an adjacency list representation of a graph:

// Each vertex is visited once.
// Each edge is traversed exactly once.
// In an adjacency matrix representation:

// Checking for neighbors takes O(V) time.
// For each vertex, visiting all neighbors results in O(V^2) time in total.
// The main difference in practice is that BFS may visit more nodes initially, as it explores all neighbors at the current level before moving on to the next level. In terms of big-O notation, both DFS and BFS are often considered equivalent in terms of time complexity for graph traversal. The choice between DFS and BFS depends on the specific requirements of the problem and the characteristics of the graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

struct Stack {
    int items[MAX_VERTICES];
    int top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

void push(struct Stack* stack, int vertex) {
    stack->items[++stack->top] = vertex;
}

int pop(struct Stack* stack) {
    return stack->items[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void initGraph(struct Graph* graph, int numVertices) 
{
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

// Function to perform depth-first search on the graph starting from a given vertex
void DFS(struct Graph* graph, int startVertex) 
{
    // Create a stack to track the traversal
    struct Stack* stack = createStack();
    // Array to mark visited vertices
    int visited[MAX_VERTICES] = {0};
    // Push the starting vertex onto the stack
    push(stack, startVertex);


    // Variable to count the number of operations
    int opcount = 0;


    // Main DFS loop
    while (!isEmpty(stack)) 
    {
        // Pop the current vertex from the stack
        int currentVertex = pop(stack);

        // Check if the vertex has been visited
        if (!visited[currentVertex]) {
            // Mark the vertex as visited and print the operation
            printf("Visited %d\n", currentVertex);
            visited[currentVertex] = 1;

            // Traverse the neighbors of the current vertex
            for (int i = graph->numVertices - 1; i >= 0; i--) 
            {
                opcount++;

                // Check for an adjacent unvisited vertex
                if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    // Push the unvisited neighbor onto the stack
                    push(stack, i);
                    printf("Pushed %d\n", i);
                }
            }
        }

        // Print the operation for popping the current vertex
        printf("Popped %d\n", currentVertex);
    }

    // Print the total number of operations performed
    printf("Total operations: %d\n", opcount);
}


int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    initGraph(graph, 6);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);

    printf("DFS Traversal: \n");
    DFS(graph, 0);

    return 0;
}
