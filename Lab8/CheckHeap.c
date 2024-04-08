// Write a program to check whether an array H[1..n] is a heap or not
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // For malloc and free

// Function to check if the given array represents a heap
bool isHeap(int arr[], int n) {
    // Start from the parent of the last node with children
    for (int i = (n - 1) / 2; i >= 1; i--) {
        // Check if the current node violates the heap property
        if (arr[i] < arr[2 * i] || arr[i] < arr[2 * i + 1])
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc((n + 1) * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isHeap(arr, n)) {
        printf("The given array is a heap.\n");
    } else {
        printf("The given array is not a heap.\n");
    }

    free(arr);
    return 0;
}
