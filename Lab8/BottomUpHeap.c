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
    //consider i as parent and n as total last no.of nodes(last pos)
    //children are always 2i and 2i+1
    //find max value element(check with left and right nodes of array respectively and store largest)
	int largest = i, left = 2*i, right = 2*i + 1;
	if(left <= n && arr[left] > arr[largest])	
        largest = left;
	if(right <= n && arr[right] > arr[largest])	
        largest = right;
	if(largest != i)//check parental dominance, if parent is not the largest, swap so that it becomes largest
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int* arr, int n)
{
	for(int i = n/2; i >= 1; i--)
	{
		heapify(arr,n,i);
	}
	for(int i = n; i >= 1; i--)
	{
		swap(&arr[1],&arr[i]);
		heapify(arr,i,0);
	}
}

int main()
{
	printf("\nEnter the number of elements:\n");
	int n; scanf("%d",&n);
	int* arr = (int*) calloc(n+1,sizeof(int));
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nOriginal Array:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ",arr[i]);
		heapSort(arr,i);
	}
	printf("\nSorted Array:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}