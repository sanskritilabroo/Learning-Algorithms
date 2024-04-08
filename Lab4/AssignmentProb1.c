#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int solve(int*arr,int** cost, int ind, int n,int minCost)
{
    if(ind == n)
    {
        int curr_cost = 0;
        for(int i = 0;i<n;i++)
        {
            curr_cost += cost[i][arr[i]]; 
        }
        if(curr_cost < minCost)
        {
            minCost = curr_cost;
        }
    }
    for(int i = ind;i<n;i++)
    {
        swap(&arr[i],&arr[ind]);
        minCost = solve(arr,cost,ind+1,n,minCost);
        swap(&arr[i],&arr[ind]);
    }
    return minCost;
}
void main()
{
    int n;
    int* arr =  (int*) calloc(n,sizeof(int));
    int** cost = (int*) calloc(n,sizeof(int));
    printf("Enter the number of employees : ");
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        *(arr+i) = i;
    }
    printf("Enter the cost matrix : \n");
    for(int i = 0 ;i<n;i++)
    {
        cost[i] = (int*) calloc(n,sizeof(int));
        printf("Enter cost for empoyee %d : ",i+1);
        for(int j= 0;j<n;j++)
        {
            scanf("%d",(*(cost+i)+j));
        }
    }
    printf("Min cost : %d ", solve(arr,cost,0,n,INT_MAX));
}