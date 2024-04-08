//Write a program to sort set of integers using bubble sort. Analyze its time
//efficiency. Obtain the experimental result of order of growth. Plot the result for
//the best and worst case.

//comparisons are general time analysis because each element is compared regardless till end of array (n(n-1)/2 comp)
//however, number of swaps vary according to whether needed or not (eg.best case is no swaps-already sorted (0 swaps)
//worst case is (n(n-1)/2 swaps)

//for graphs, general graph is only comparison opcount (n(n-1)2) in any case
//best and worst graph is considering swap as basic operation
//swap worst graph same as comparison graph

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *a, unsigned int n)
{ 
	unsigned int i,j;
	int temp;
	int opcount1=0; 
	int opcount2=0;

	for(i=0; i<=n-2 ; i++)
	{
		for(j=0; j<=n-2-i ;j++)
		{
			++opcount1;
			if(a[j] > a[j+1])//comparison is the basic operation
			{
				//swap A[j] and A[j+1]
				++opcount2;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nComparison Count %d\n",opcount1);
	printf("Swap Count %d\n",opcount2);
}


int main() 
{
	int *a;
	int i,n;	
	printf("\nEnter no.of elements ");
	scanf("%d",&n);

	a = (int *)malloc(sizeof(int)*n);

	for (int k=0; k<n; k++)
		scanf("%d",&a[k]);


	printf("\nElements are ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);


	bubbleSort(a,n);
    
	printf("Elements after bubble sort ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");


	free(a);
	return 0;
}