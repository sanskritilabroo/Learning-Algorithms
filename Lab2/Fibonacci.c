#include <stdio.h>

int fibonacci(int n, int* opCount) {
    if (n <= 1) {
        (*opCount)++;
        return n;
    }

    (*opCount)++;
    return fibonacci(n - 1, opCount) + fibonacci(n - 2, opCount);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int opCount = 0;
    int result = fibonacci(n, &opCount);

    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Total number of basic operations: %d\n", opCount);

    return 0;
}
