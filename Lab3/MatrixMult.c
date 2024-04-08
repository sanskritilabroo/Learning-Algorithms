// Write a program to implement matrix multiplication using brute-force technique 
//  and analyze its time efficiency. Obtain the experimental result of order of growth. 
// Plot the result for the best and worst case.

#include <stdio.h>

#define MAX_SIZE 5

void multiply(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int R[MAX_SIZE][MAX_SIZE], int r, int c, int k) {
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            for (int l = 0; l < k; ++l)
                R[i][j] += A[i][l] * B[l][j];
}

void display(int M[MAX_SIZE][MAX_SIZE], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], R[MAX_SIZE][MAX_SIZE];
    int rA, cA, rB, cB;

    printf("Enter dimensions of matrix A (rows columns): ");
    scanf("%d%d", &rA, &cA);

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rA; ++i)
        for (int j = 0; j < cA; ++j)
            scanf("%d", &A[i][j]);

    printf("Enter dimensions of matrix B (rows columns): ");
    scanf("%d%d", &rB, &cB);

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rB; ++i)
        for (int j = 0; j < cB; ++j)
            scanf("%d", &B[i][j]);

    if (cA != rB) {
        printf("Error: Incompatible matrices for multiplication\n");
        return 1;
    }

    for (int i = 0; i < rA; ++i)
        for (int j = 0; j < cB; ++j)
            R[i][j] = 0;

    multiply(A, B, R, rA, cB, cA);

    printf("Resultant matrix:\n");
    display(R, rA, cB);

    return 0;
}
