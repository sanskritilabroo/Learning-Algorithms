//  Write a program to implement 0/1 Knapsack problem using bottom-up dynamic programming

#include <stdio.h>
#include <stdlib.h>

int maxim(int a, int b)
{
	if(a > b)	return a;
	return b;
}

int main()
{
	printf("\nEnter the number of objects:\n");
	int n; scanf("%d",&n);
	printf("\nEnter the weights and profits of each:\n");
    int* w = (int *)malloc(n * sizeof(int));
    int* p = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		printf("\nObject %d:\nWeight:\t",i+1);
		scanf("%d",&w[i]);
		printf("Profit:\t");
		scanf("%d",&p[i]);
	}
	printf("\nEnter the weight of the knapsack:\n");
	int max;	
    
    scanf("%d",&max);
	int dp[n+1][max+1];

	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= max; j++)
		{
			if(i == 0 || j == 0)	
                dp[i][j] = 0;
			else if(j-w[i-1] >= 0)	
                dp[i][j] = maxim(dp[i-1][j],dp[i-1][j-w[i-1]] + p[i-1]);
			else	
                dp[i][j] = dp[i-1][j];
		}
	}
	printf("\nResult:\t%d",dp[n][max]);
	return 0;
}