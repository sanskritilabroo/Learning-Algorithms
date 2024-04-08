#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_VERTICES 100

typedef struct Graph
{
    int numVertices;
    int adjMat[][SIZE];
}Graph;

typedef struct Stack {
    int items[MAX_VERTICES];
    int top;
}Stack;

Stack* createStack()
{
    Stack* s = malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push(Stack* s, int vertex) {
    s->items[++s->top] = vertex;
}

int pop(Stack* s) {
    return s->items[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void initGraph(Graph* g, int numVertices) 
{ 
    g->numVertices = numVertices;
    for(int i=0;i<numVertices;i++)
        for(int j=0;j<numVertices;j++)
            g->adjMat[i][j] = 0;
}

void addEdge(Graph* g, int src, int dst)
{
    g->adjMat[src][dst] = 1;
}

void DFS(Graph* g, int startVertex) 
{
    Stack *s = createStack();
    int visited[MAX_VERTICES] = {0};
    push(s, startVertex);

    int opcount = 0;

    while(!isEmpty(s))
    {
        int current = pop(s);

        if(!visited[current])
        {
            printf("Visited %d\n", current);
            visited[current] = 1;//now mark as visited
            for (int i = g->numVertices - 1; i >= 0; i--) //loop through all the neighboring vertices
            {
                opcount++;//comparison
                if (g->adjMat[current][i] == 1 && !visited[i]) {
                    //if edge from current to some neighboring vertex i is existing and still unvisited, now push
                    push(s, i); printf("Pushed %d\n", i);//push the vertex
                }
            }
        }
    }


}