#include <stdio.h>
#include <stdlib.h>

int ** multiply(int **a, int **b, int **c, int r1, int r2, int c1, int c2)
{
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++)
            {
                sum += (*(*(a+i)+k)) * (*(*(b+k)+j));
            }
        *(*(c+i)+j) = sum;
        }
    }
    return c;
}

int main(){
	int r1,c1,r2,c2,**p,**a,**b,**c;
	printf("Enter dimensions of a:"); 
	scanf("%d%d",&r1,&c1);
	printf("Enter dimensions of b:"); 
	scanf("%d%d",&r2,&c2);

	if (c1!=r2)
	{
		printf("Not possible");
		exit(0);
	}
	// Allocate memory for matrices a, b, and c
    a = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
        a[i] = (int *)malloc(c1 * sizeof(int));

    b = (int **)malloc(r2 * sizeof(int *));
    for (int i = 0; i < r2; i++)
        b[i] = (int *)malloc(c2 * sizeof(int));

    c = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++)
        c[i] = (int *)malloc(c2 * sizeof(int));

    // Populate matrices a and b with values
    printf("Enter values for matrix a:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter values for matrix b:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    p = multiply(a, b, c, r1, r2, c1, c2);
    // Print the resulting matrix c
    printf("Resultant matrix c:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", *(*(p+i)+j));
        }
        printf("\n");
    }

    // Free memory for matrices a, b, c
    for (int i = 0; i < r1; i++)
        free(a[i]);
    free(a);

    for (int i = 0; i < r2; i++)
        free(b[i]);
    free(b);

    for (int i = 0; i < r1; i++)
        free(c[i]);
    free(c);

    return 0;
}