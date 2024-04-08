// Write a program to create a heap for the list of integers using top-down heap 
// construction algorithm and analyze its time efficiency. Obtain the experimental 
// results for order of growth and plot the result.
#include <stdio.h>
#include <stdlib.h>

int op = 0;


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void topDown(int arr[], int currIndex)
{
    int parent = (currIndex - 1)/2;
    while(parent >= 0)
    {
	op++;
        if(arr[parent]<arr[currIndex])
        {//parental dominance is false so swap
            swap(&arr[parent],&arr[currIndex]);
            currIndex = parent;
            parent = (currIndex - 1)/2;
        }
        else
            return;
    }
}

int main()
{
    int h[20], n;
    printf("Enter no. of elements:\n");
    scanf("%d", &n);
    printf("Enter Elements:\n");
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &h[i]);

        topDown(h, i);

		for(int k = 0; k<=i; k++)
			printf("%d ", h[k]);
		printf("\n");
    }
    
    printf("Heapified array:\n");
    for(int i = 0; i<n; i++)
        printf("%d ", h[i]);
    printf("\n");

    printf("OP = %d\n", op);

    exit(0);
    return 0;
}
