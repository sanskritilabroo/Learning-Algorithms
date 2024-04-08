#include <stdio.h>
#include <stdlib.h>

int main() {
    int v;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &v);

    int **graph = (int **)malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        graph[i] = (int *)malloc(v * sizeof(int));
    }

    // Input the adjacency matrix
    for (int i = 0; i < v; i++) {
        printf("\nEnter edges values for Vertex %d: ", i);
        for (int j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n\nInitial Graph\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    // Finding transitive closure
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    printf("\n\nTransitive Closure:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < v; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
