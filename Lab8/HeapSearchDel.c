#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i)
{
    // Consider i as parent and n as total last no.of nodes(last pos)
    // Children are always 2i and 2i+1
    // Find max value element (check with left and right nodes of array respectively and store largest)
    int largest = i, left = 2 * i, right = 2 * i + 1;
    if (left <= n && arr[left] > arr[largest])
        largest = left;
    if (right <= n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) // Check parental dominance, if parent is not the largest, swap so that it becomes largest
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, i - 1, 1); // Change to heapify from index 1 to i-1 after deletion
    }
}

int findIndex(int* arr, int n, int value)
{
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1; // Return -1 if value not found
}

void deleteElement(int* arr, int* n, int value)
{
    int index = findIndex(arr, *n, value);
    if (index == -1)
    {
        printf("Element not found in the heap.\n");
        return;
    }
    arr[index] = arr[*n];
    (*n)--;
    heapify(arr, *n, index); // Heapify from the index of the deleted element
    printf("Element %d has been deleted from the heap.\n", value);
}

int main()
{
    printf("\nEnter the number of elements:\n");
    int n;
    scanf("%d", &n);
    int* arr = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal Array:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    heapSort(arr, n);
    printf("\nSorted Array:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Delete an element from the heap
    int value;
    printf("\nEnter the value to delete from the heap: ");
    scanf("%d", &value);
    deleteElement(arr, &n, value);

    printf("\nThe heap after deletion:");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
