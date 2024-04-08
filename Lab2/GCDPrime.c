#include <stdio.h>
#include <math.h>

int isPrime(int n, int * opCount) {
    int i, count = 0;
    for(i=2; i*i<n; i++) {
        *opCount += 1; //prime checking condition is critical op.
        if (n % i == 0) //has a factor so not a prime so return 0
            return 0;
    }
    return 1; //has no factors so prime so return 1
}

void main() {
    int gcd = 1, n1, n2, i = 2, x, y, opCount = 0;
    printf("Enter the 2 numbers ");
    scanf("%d %d",&n1,&n2);
    x = n1 < n2 ? n1 : n2;
    y = n1 > n2 ? n1 : n2;
    // Iterate from 2 to the smaller of the two numbers (x) to find common factors
    for (int i = 2; i <= x; i++) {
        opCount++; // Increment the operation count for each iteration

        // Check if both x and y are divisible by the current factor (i)
        if ((x % i == 0) && (y % i == 0)) {
            // If the current factor is a prime number
            if (isPrime(i, &opCount)) {
                // Reduce x and y by dividing them by the common prime factor (i)
                x /= i;
                y /= i;

                // Multiply the GCD by the common prime factor
                gcd *= i;

                // Decrement i to re-check the same factor (important for composite factors)
                i--;
            }
        }
    }
    printf("The GCD of %d and %d is : %d\nOpCount is %d\n", n1, n2, gcd, opCount );
}
