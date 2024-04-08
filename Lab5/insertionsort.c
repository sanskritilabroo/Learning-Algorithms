#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    printf("\nEnter number of elements:\n");
    int n; scanf("%d",&n);
    int* arr = (int*) calloc(n,sizeof(int));
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand()%1000;
    }
    
    printf("\nArray:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    insertionSort(arr,n);

    printf("\nSorted:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}