// Write a program to delete strong numbers from an array using recursion [A strong 
// number is such that the sum of it's factorial is the number itself]

#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Function to check if a number is a strong number
int isStrong(int num) {
    int originalNum = num;
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return (sum == originalNum);
}

// Function to delete strong numbers from an array using recursion
void deleteStrongNumbers(int array[], int *size, int index) {
    if (index == *size) {
        return;
    }

    if (isStrong(array[index])) {
        // If the current element is a strong number, remove it
        for (int i = index; i < *size - 1; i++) {
            array[i] = array[i + 1];
        }
        (*size)--; // Decrease the size of the array
    } else {
        // Move to the next element
        deleteStrongNumbers(array, size, index + 1);
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* array = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    deleteStrongNumbers(array, &size, 0);

    printf("Array after deleting strong numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
